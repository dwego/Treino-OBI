placa = input()
if placa[3] == '-' and placa[:3].isalpha() and placa[4:].isdigit() and len(placa) == 8:
    print(1)
elif placa[3].isdigit() and placa[:3].isalpha() and placa[4].isalpha() and placa[5:].isdigit() and len(placa) == 7:
    print(2)
else:
    print(0) 