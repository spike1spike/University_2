def calculateMax(lst):
    return max(lst)

def findListWithMaxValue(listA, listB):
    maxA = calculateMax(listA)
    maxB = calculateMax(listB)

    if maxA > maxB:
        print(f'Массив A содержит наибольшее значение {maxA} с порядковым номером {listA.index(maxA)+1}')
        print('Элементы массива A:')
        print(*[elem for elem in listA], sep = ' ')
    else:
        print(f'Массив B содержит наибольшее значение {maxB} с порядковым номером {listB.index(maxB)+1}')
        print('Элементы массива B:')
        print(*[elem for elem in listB], sep = ' ')

A = []
B = []

sizeA = 5
sizeB = 4

print(f'Введите {sizeA} элементов для массива A: ')
for i in range(sizeA):
    A.append(int(input()))
print(f'Введите {sizeB} элементов для массива B: ')
for i in range(sizeB):
    B.append(int(input()))

findListWithMaxValue(A, B)

input('Нажмите Enter для завершения программы...')