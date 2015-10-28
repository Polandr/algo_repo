# -*- coding: Windows-1251 -*-

# ������������� ��������� ��������
# - �� ����� - ����� elements � ���� slots.txt
# - �� ������ - ����� elements2 � ���� system.js

import sys, json

# ������� ��� ���� contains
def contains(t):
  if t.has_key("contains"):
    return t["contains"]
  return []

# �������� �� ������ t ��� ������������� � ������� �����
def available(t, config):
  if not t.has_key("depends"):
    return True # ��� ����������� -> ��������
  for c in t["depends"].keys():
    if c not in config.keys():
      return False # ����������� ���� -> ����������
    if config[c] not in t["depends"][c]:
      return False # �������� ���� �� ������� -> ����������
  return True # ��� ������� ��������� -> ��������

# ������ � ������������� � ���������� ����������������� �����  
def make_config(elements):
  config = {} # ��������� ������������� ������������
  params = {} # �������� ���������� � ��������� ������������� ��������
  slots = ["program"] # ������ ������, ���������� �����������
  for e in elements: # ���������� ��� ����� � system.js 
    slot, text, templates = e[0], e[1], e[2:]
    if slot in slots: # ���� �������� �����������?
      # ������� ������ ��������� �������� ��� ������� �����
      print text+":"
      ind, k = [], 0
      for i in range(len(templates)):
        if available(templates[i], config):
          print k+1, templates[i]["title"]
          ind.append(i)
          k += 1
      a = raw_input(">") # ����� ������������
      if a!="": 
        a = int(a)-1
      else: 
        a = 0 # �� ��������� (����� ������ Enter) ����� ������ �������
      slots += contains(templates[ind[a]]) # ��������� ������ ������ 
      config[slot] = templates[ind[a]]["id"] # ���������� ����� ������������
      # ��������� ���������� 
      if templates[ind[a]].has_key("params"):
        for p in templates[ind[a]]["params"]:
          print "  ", p[3], "("+p[0]+")",
          v = raw_input(": ")
          if v!="": 
            params[p[1]] = v
          else:
            params[p[1]] = p[2] # �������� �� ���������
      print
  return config, params

# �������� �������
def main():
  #sdata = "".join(open(sys.argv[1],"r").readlines())
  sdata = open(sys.argv[1],"r").read()
  data = json.loads(sdata.decode("windows-1251"))
  config, params = make_config(data)

  f = open("user.js","w")
  print >> f, json.dumps([config, params], indent=4)
  f.close()
  
main()