import json

def getreclist(data, key):
  L = []
  if "body" in data:
    for r in data["body"]:
      if r["key"]==key:
        L.append(r)
  return L  

def getdic(data):
  dic = {}
  for k in data.keys():
    if k!="key" and k!="body":
      dic[k] = data[k]
  return dic

def modify(s, vars):
  r, pos = '', 0
  s += "\0"
  while s[pos]!='\0':
    if s[pos]=='$':
      p2 = s.find('$',pos+1)
      varname = s[pos+1:p2]
      if varname in vars: 
        r += vars[varname]
      pos = p2+1
    else:
      r += s[pos]
      pos += 1
  return r

def loadtemplate(fname):
  t = open(fname,"r").readlines()
  T = []
  for x in t:
    T.append(x)
  return T
  
def apply(text, data, vars={}, includes=[]):
  S = []
  i = 0
  while i<len(text):
    s = text[i]
    if s[:3]=="//:":
      if s[3:7]=="LOAD":
        fname = modify(s[7:].strip(),vars)
        if fname not in includes:
          text[i:] = loadtemplate("elements2\\"+fname) + text[i+1:]
          includes.append(fname)
        else:
          i += 1 
      else:
        sname = s[3:].strip()[:-1]
        k = i+1
        while sname+"-" not in text[k]:
          k += 1
        R = getreclist(data, sname)
        for r in R:
          text2 = text[i+1:k]
          vars2 = {}
          vars2.update(vars)
          vars2.update(getdic(r))
          S += apply(text2,r,vars2)
        i = k+1
    else:
      S.append(modify(s, vars))    
      i += 1
  return S  
  
def main():
  text = loadtemplate("elements2\\program_default.cpp")
  data = json.loads(open("config.js","r").read()) #.decode("windows-1251"))
  S = apply(text, data, {}, [])

  f = open("output.cpp","w")
  f.write("".join(S)) #.encode("windows-1251")
  f.close()
  
main()

