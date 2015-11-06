# -*- coding: UTF-8 -*-

# Предобработка заготовок шаблонов
# - на входе - папка elements и файл slots.txt
# - на выходе - папка elements2 и файл system.js

import sys, os, json
from parse import parse

fnames = os.listdir("elements")

templ = []

# Просматриваем все файлы в папке elements
for fn in fnames:
  if fn[0] == "_":
    # модуль общего назначения, простое копирование
    f = open("elements2\\"+fn[1:],"w")
    #print >> f, open("elements\\"+fn).read(),
    f.write(open("elements\\"+fn).read())
    f.close()
  else:
    # шаблон, производим его разбор с помощью функции parse
    templ.append(parse("elements\\"+fn))

Slots = [] # список всех слотов, каждый слот представлякт собой JSON объект
sid = {} # slot id (position in Slots)

# просматриваем список слотов в файле slots.txt 
# важен порядок, в котором перечислены слоты 
for x in open("slots.txt","r"):
  t = x.strip().split(" ")
  slotname, slotinfo = t[0], " ".join(t[1:])
  sid[slotname] = len(Slots)
  Slots.append([slotname, slotinfo]) 

# просматриваем все шаблоны, выделенные в папке elements
for x in templ:
  s, id = x["slot"], x["id"]
  t = {} # вся информация о шаблоне (JSON)
  t["id"] = id
  t["title"] = x["title"]
  t["contains"] = x["slots"]
  for k in ["params", "depends", "include", "details", "vars", "switches", "types"]:
    #if x.has_key(k):
    if k in x:
      t[k] = x[k]
  # присоединяем информацию о шаблоне к соответствующему слоту
  Slots[sid[s]].append(t)
  # создаем файл с кодом (без метаинформации)
  f = open("elements2\\"+s+"_"+id+".cpp","w")
  #print >> f, x["code"]
  f.write(x["code"]);
  f.close()

f = open("system.js","w")
f.write(json.dumps(Slots, ensure_ascii=False, indent=4))
f.close()

  