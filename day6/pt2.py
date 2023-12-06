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
    return res

with open(nombre_archivo, 'r') as archivo:
    for linea in archivo:
        palabras = linea.split()

        if palabras[0] == "Time:":
            tiempos.extend(map(int, palabras[1:]))
        elif palabras[0] == "Distance:":
            distancias.extend(map(int, palabras[1:]))

    # Concateno
    t = int(''.join(map(str, tiempos)))
    d = int(''.join(map(str, distancias)))
    
    res = waysToWin(t,d)
    print(res)