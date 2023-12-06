tiempos = []
distancias = []

nombre_archivo = "input.txt"

def waysToWin(time,dist):
    res = 0
    vel = 0
    met = 0
    for i in range(1, time):
        vel = i
        met = vel * (time- i)
        if met > dist:
            res += 1

    print(res)
    return res

with open(nombre_archivo, 'r') as archivo:
    for linea in archivo:
        palabras = linea.split()

        if palabras[0] == "Time:":
            tiempos.extend(map(int, palabras[1:]))
        elif palabras[0] == "Distance:":
            distancias.extend(map(int, palabras[1:]))

res = 1
for i in range(0, len(tiempos)):
    val = waysToWin(tiempos[i],distancias[i])
    res = res * val

print(res)



# print(tiempos[0])
# print("Tiempos:", tiempos)
# print("Distancias:", distancias)
