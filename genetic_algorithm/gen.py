# -*- coding: Windows-1251 -*-

# ���������� ������ ��� ���������������� ��������� ����

import json

# ������� ��� ������ �������� �� �����
def get_val(config, key):
  if config.has_key(key):
    return config[key]
  return ""   

# ���������� ������ ��� ��������� ����
def make_config(system, user):
  vars = {} # ������ ���������� � ������ GLOBAL
  body = [] # ������ ������ (PARAMETER, INCLUDE, SWITCH � �.�.
  
  slots = user[0] # ��������� ������������� ������������ ���������
  params = user[1] # ��������� ���� ��������� ������������� ��������

  # ���� �� ���� ������ � system.js
  for e in system:
    slot = e[0]
    template = get_val(slots, slot)
    vars[slot] = template
    # ���� �� ���� �������� �������� �����
    for c in e[2:]:
      if c["id"]==template:
        # ���� ������������� ���� ������� ������ ���������� ����+������...
        vars[slot+"_details"] = get_val(c,"details") 
        if c.has_key("params"): 
          # ��������� ���������� ������� 
          for p in c["params"]:
            d = {"key":"PARAMETER"}
            d["type"] = p[0]
            d["name"] = p[1]
            d["val"] = params[p[1]]
            d["details"] = p[3]
            body.append(d)       
        if c.has_key("types"): 
          # �������� �������������� ����� (����������� ���������)
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
          # ��������� ������������ ������������ ������
          for i in c["include"]:
            d = {"key":"INCLUDE", "header":i} 
            body.append(d)
        if c.has_key("vars"):
          # ��������� �������������� ����������
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