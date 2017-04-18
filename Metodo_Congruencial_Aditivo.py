#Metodo Congruencial Aditivo
#Generar 7 numeros pseudo aleatorios entre cero y uno a partir de la 
#siguiente secuencia de numeros enteros: 65,89,98,03,69; m=100
def secuencia (numero,cnum):
	for i in range(cnum):
		x=float(input("Ingrese el numero  : "))
		numero.append(x)
	return numero
def MCA(numero,Ite,m):
	ini=0
	fin=len(numero)-1
	for i in range(Ite):
		numero.append((numero[fin]+numero[ini])%m)
		ini+=1
		fin+=1
	return numero
			
numero=[]
cnum=int(input("Ingrese el numero de secuencias que va a ingresar : "))
numero= secuencia(numero,cnum)
Ite=int(input("Ingrese el numero de Iteraciones : "))
m=int(input("Ingrese el valor de M : "))
numero=MCA(numero,Ite,m)
for i in range(cnum,len(numero)):
	if (i+1<10):
		print 'X',i+1,'  = ',"%.4f"%(numero[i]/99)
	elif(i+1>=10):
		print 'X',i+1,' = ',"%.4f"%(numero[i]/99)
	

