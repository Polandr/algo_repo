# -*- coding: UTF-8 -*-

# ищем в коде все слоты 
def find_slots(text):
  T = text.split("\n")
  slots = []
  for k in range(len(T)):
    t = T[k]
    if t[:7]=="//:SLOT":
      slot = t[7:].strip()
      slots.append(slot) # запоминаем слот
      # заменяем слот на команду загрузки файла
      T[k] = "//:LOAD "+slot+"_$"+slot+"$.cpp" 
  return "\n".join(T), slots

# готовим список подключаемых заголовочных файлов
def make_includes(text):
  I = []
  for i in text.split("\n"):
    I.append(i.strip())
  return I

# готовим список параметров
def make_parameters(text):
  P = []
  T = text.split("\n")
  for t in T:
    S = t.split(" ")
    P.append([S[0],S[1],S[2]," ".join(S[3:])])
  return P

# готовим список дополнительных типов
def make_types(text):
  A = []
  T = text.split("\n")
  for t in T:
    S = t.split(" ")
    A.append([S[0],S[1],S[2]," ".join(S[3:])])
  return A 

# многострочные комментарии
def make_details(text):
  D = ""
  T = text.split("\n")
  for t in T:
    D += "// "+t+"\n"
  return D[:-1]

# готовим список (словарь) переменных 
def make_vars(text):
  V = {}
  T = text.split("\n")
  for t in T:
    S = t.split(" ")
    V[S[0]] = S[1]
  return V

# готовим список опций 
def make_switches(text):
  S = []
  T = text.split("\n")
  for t in T:
    S.append(t.strip())
  return S

# составляем список условий, при выполнении которых может быть 
# использован данный шаблон
def make_depends(text):
  l = text.split("\n")
  ifs = {}
  for x in l:
    key, val = x.split("=")
    if key not in ifs.keys():
      ifs[key] = [val]
    else:
      ifs[key].append(val)
  return ifs

# разделение шаблона на секции, анализ каждой секции
def parse(fname):
  slot = fname[fname.find("\\")+1:fname.find("_")]
  id = fname[fname.find("_")+1:fname.find(".")]
  lines = open(fname,"r").readlines()
  D = {"slot":slot, "id":id} # вся информация о шаблоне
  Slots = [] # список слотов в данном шаблоне
  key = ""
  val = ""
  for l in lines:
    if l[0]=='[':
      if key != "": 
        D[key] = val.rstrip()
      if key=="code":
        D[key], Slots = find_slots(D[key])
      if key=="params":
        D[key] = make_parameters(D[key])
      if key=="types":
        D[key] = make_types(D[key])
      if key=="include":
        D[key] = make_includes(D[key])
      if key=="depends":
        D[key] = make_depends(D[key])
      if key=="vars":
        D[key] = make_vars(D[key])
      if key=="details":
        D[key] = make_details(D[key])
      if key=="switches":
        D[key] = make_switches(D[key]) 
      key = l[1:l.find("]")]
      if key=="end":
        break
      val = ""
    else:
      val += l
  D["slots"] = Slots                   
  return D

