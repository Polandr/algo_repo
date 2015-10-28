# -*- coding: Windows-1251 -*-

# ������������� ��������� ��������
# - �� ����� - ����� elements � ���� slots.txt
# - �� ������ - ����� elements2 � ���� system.js

import sys, os, json
from parse import parse

fnames = os.listdir("elements")

templ = []

# ������������� ��� ����� � ����� elements
for fn in fnames:
  if fn[0] == "_":
    # ������ ������ ����������, ������� �����������
    f = open("elements2\\"+fn[1:],"w")
    print >> f, open("elements\\"+fn).read(),
    f.close()
  else:
    # ������, ���������� ��� ������ � ������� ������� parse
    templ.append(parse("elements\\"+fn))

Slots = [] # ������ ���� ������, ������ ���� ������������ ����� JSON ������
sid = {} # slot id (position in Slots)

# ������������� ������ ������ � ����� slots.txt 
# ����� �������, � ������� ����������� ����� 
for x in open("slots.txt","r"):
  t = x.strip().split(" ")
  slotname, slotinfo = t[0], " ".join(t[1:])
  #print slotname, slotinfo
  sid[slotname] = len(Slots)
  Slots.append([slotname, slotinfo]) 

# ������������� ��� �������, ���������� � ����� elements
for x in templ:
  s, id = x["slot"], x["id"]
  t = {} # ��� ���������� � ������� (JSON)
  t["id"] = id
  t["title"] = x["title"]
  t["contains"] = x["slots"]
  for k in ["params", "depends", "include", "details", "vars", "switches", "types"]:
    if x.has_key(k):
      t[k] = x[k]
  # ������������ ���������� � ������� � ���������������� �����
  Slots[sid[s]].append(t)
  # ������� ���� � ����� (��� ��������������)
  f = open("elements2\\"+s+"_"+id+".cpp","w")
  print >> f, x["code"]
  f.close()

f = open("system.js","w")
print >> f, json.dumps(Slots, ensure_ascii=False, indent=4)
f.close()

  