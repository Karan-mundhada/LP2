def ques(sent: str) -> bool:
    res = input(sent +": ").lower().split()[0]
    return res == "y"

def allergies()-> bool:
    return ques("do you have ithing or swelling?") and ques("do you have red watery eyes?")

def fever()->bool:
    return ques("Is your temp above 37.6?") and ques("any chills")

def flu()->bool:
    return ques("temp above 38") and ques("tired, fatiqued, body aches?")

def cold():
    return ques("runny nose") and ques("sneezing?")
    
def steepthroat():
    return ques("pain in the back of your throat when you swallow?")

def apendics():
    return ques("lower abdominal pain?") and ques("loss of appetite")

def food_poison()->bool:
    return ques("diarrhea ?") and ques("vomitting") and ques("nausea")

print("Expert syus")

def main():
    if allergies():
        print("You have allergies")
    else:
        print("you dont have allergies")

    if fever():
        print("You have fever")
    else:
        print("you dont have fever")

    if flu():
        print("You have flu")
    else:
        print("you dont have flu")

    if cold():
        print("You have cold")
    else:
        print("you dont have cold")

    if food_poison():
        print("You have food_poisoning")
    else:
        print("you dont have food")

    if apendics():
        print("You have apendics")
    else:
        print("you dont have apendics")

if __name__ == "__main__":
    main()