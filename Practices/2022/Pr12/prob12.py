text = []
while True:
    data = input()
    if data == "End":
        break
    else:
        place = data
    

    while True:
        data = input()
        if data == "":
            break
        else:
            text.extend(data.split())
    
    bunch = "".join(text).lower()

    if  "lead" in bunch and "flexib" in bunch and "involve" in bunch and "plan" in bunch:
        print(place + ": " + "Meets standards")
        # print(f"{place}: Meets standards")
    else:
        print(place + ": " + "Does not meet standards")
        # print(f"{place}: Does not meet standards")
    print()
    
    text = []