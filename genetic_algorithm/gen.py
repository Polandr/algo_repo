# -*- coding: Windows-1251 -*-

# Подготовка данных для непосредственной генерации кода

import json

# обертка для поиска значения по ключу
def get_val(config, key):
  if config.has_key(key):
    return config[key]
  return ""   

# подготовка данных для генерации кода
def make_config(system, user):
  vars = {} # список переменных в секции GLOBAL
  body = [] # список секций (PARAMETER, INCLUDE, SWITCH и т.д.
  
  slots = user[0] # выбранная пользователем конфигурация алгоритма
  params = user[1] # параметры всех выбранных пользователем шаблонов

  # цикл по всем слотам в system.js
  for e in system:
    slot = e[0]
    template = get_val(slots, slot)
    vars[slot] = template
    # цикл по всем шаблонам текущего слота
    for c in e[2:]:
      if c["id"]==template:
        # если пользователем была выбрана данная комбинация слот+шаблон...
        vars[slot+"_details"] = get_val(c,"details") 
        if c.has_key("params"): 
          # обработка параметров шаблона 
          for p in c["params"]:
            d = {"key":"PARAMETER"}
            d["type"] = p[0]
            d["name"] = p[1]
            d["val"] = params[p[1]]
            d["details"] = p[3]
            body.append(d)       
        if c.has_key("types"): 
          # оработка дополнительных типов (кодирование популяции)
          for t in c["types"]:
            d = {"key":""}
            if t[2] == "array":
              d["key"] = "ATYPE"
            else:
              d["key"] = "STYPE"   
            d["type"] = t[0]
            d["name"] = t[1]
            d["details"] = t[3]
            body.append(d)       
        if c.has_key("include"):
          # обработка подключаемых заголовочных файлов
          for i in c["include"]:
            d = {"key":"INCLUDE", "header":i} 
            body.append(d)
        if c.has_key("vars"):
          # обработка дополнительных переменных
          for v in c["vars"].keys():
            vars[v] = c["vars"][v]
        if c.has_key("switches"):
          for s in c["switches"]:
            body.append({"key":s}) 

  vars.update({"key":"GLOBAL", "body":body})
  return {"body": [ vars ] }
                  
def main():
  system = json.loads(open("system.js","r").read().decode("windows-1251"))
  user = json.loads(open("user.js","r").read().decode("windows-1251"))

  config = make_config(system, user)

  f = open("config.js","w")
  print >> f, json.dumps(config, indent=4, ensure_ascii=False).encode("windows-1251")
  f.close()
  
main()