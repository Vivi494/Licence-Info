from pycsp3 import *

n=int(input('Quelle est la taille du carré magique ?'))
x=VarArray(size=[n,n],dom=range(1,n*n+1))
print(x)
print("Domain of any variable: ",x[0][0].dom)
nn: int=int(n*(n*n+1)/2)
nn_mag: int=int(n*(n*n+1)*(2*n*n+1)/6)
print("nn:",nn)
if n == 8:
    clues = [
            [56, None, 8, None, 18, None, 9, None],
            [None, 20, None, None, 7, None, None, 10],
            [26, None, 13, 23, None, 38, None, None],
            [None, None, 35, 30, None, 12, None, 60],
            [None, 25, None, None, 41, None, 50, None],
            [None, None, 17, None, 36, None, 32, None],
            [None, 16, None, 52, None, 1, None, None],
            [44, None, 28, 37, None, None, 21, None]
            ]
satisfy(
    [AllDifferent(x[0:0+n,0:0+n])],
    [Sum(x[i])==nn for i in range (n)],
    [Sum([x[i][i] for i in range (n)])==nn],
    [Sum([x[n-1-i][i] for i in range (n)])==nn],
    [Sum([x[i][j]for i in range (n)])==nn for j in range (n)],
    [x[i][j] == clues[i][j] for i in range(8) for j in range(8) if n==8 if clues[i][j] != None]
);
if solve() is SAT:
    print(values(x))
else:
    print("pas de solutions")

satisfy(
    [Sum([x[i][j]*x[i][j] for j in range (n)])==nn_mag for i in range (n)],
    [Sum([x[i][i]*x[i][i] for i in range (n)])==nn_mag],
    [Sum([x[n-1-i][i]*x[n-1-i][i] for i in range (n)])==nn_mag],
    [Sum([x[i][j]*x[i][j] for i in range (n)])==nn_mag for j in range (n)]
);
if solve() is SAT:
    print("il est bi-magique")
else:
    print("il n'est pas bi-magique")