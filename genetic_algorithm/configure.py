# -*- coding: UTF-8 -*-

# Предобработка заготовок шаблонов
# - на входе - папка elements и файл slots.txt
# - на выходе - папка elements2 и файл system.js

import sys, json

# обертка для поля contains
def contains(t):
  if  "contains" in t:
    return t["contains"]
  return []

# доступен ли шаблон t для использования в текущем слоте
def available(t, config):
  if not "depends" in t:
    return True # нет ограничений -> доступен
  for c in t["depends"].keys():
    if c not in config.keys():
      return False # отсутствует слот -> недоступен
    if config[c] not in t["depends"][c]:
      return False # нарушено одно из условий -> недоступен
  return True # все условия выполнены -> доступен

# диалог с пользователем и подготовка конфигурационного файла  
def make_config(elements):
  config = {} # выбранная пользователем конфигурация
  params = {} # значения параметров в выбранных пользователем шаблонах
  slots = ["program"] # список слотов, подлежащих детализации
  for e in elements: # перебираем все слоты в system.js 
    slot, text, templates = e[0], e[1], e[2:]
    if slot in slots: # слот подлежит детализации?
      # выводим список доступных шаблонов для данного слота
      print(text+":");
      ind, k = [], 0
      for i in range(len(templates)):
        if available(templates[i], config):
          print(k+1, templates[i]["title"])
          ind.append(i)
          k += 1
      a = input(">") # выбор пользователя
      if a!="": 
        a = int(a)-1
      else: 
        a = 0 # по умолчанию (нажат только Enter) берем первый вариант
      slots += contains(templates[ind[a]]) # обновляем список слотов 
      config[slot] = templates[ind[a]]["id"] # запоминаем выбор пользователя
      # настройка параметров 
      if "params" in templates[ind[a]]:
        for p in templates[ind[a]]["params"]:
          print("  ", p[3], "("+p[0]+")")
          v = input(": ")
          if v!="": 
            params[p[1]] = v
          else:
            params[p[1]] = p[2] # значение по умолчанию
      print
  return config, params

# головная функция
def main():
  #sdata = "".join(open(sys.argv[1],"r").readlines())
  sdata = open("system.js","rb").read()
  data = json.loads(sdata.decode("utf-8")) #.decode("windows-1251"))
  config, params = make_config(data)

  f = open("user.js","w")
  f.write(json.dumps([config, params], ensure_ascii=False, indent=4))
  f.close()
  
main()