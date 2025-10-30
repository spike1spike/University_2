def getSetDifference(setA, setB):
    return setA - setB

def findMaxElement(setA, setB):
    result = getSetDifference(setA, setB)

    max_el = max(result)

    print(f'Максимальный элемент разницы множеств A и B: {max_el}')

sA = int(input('Введите размер множества A: '))
sB = int(input('Введите размер множества B: '))

stA = set()
stB = set()

print(f'Введите {sA} элементов множества A:')
for i in range(sA):
    stA.add(int(input()))
print(f'Введите {sB} элементов множества B:')
for i in range(sB):
    stB.add(int(input()))

findMaxElement(stA, stB)

input('Нажмите Enter для завершения программы...')