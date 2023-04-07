def sorting():
    numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
    people = [('Hal', 20), ('Susann', 31), ('Dwight', 19), ('Kassandra', 21), ('Lawrence', 25), ('Cindy', 22), ('Cory', 27), ('Mac', 19), 
                ('Romana', 27), ('Doretha', 32), ('Danna', 20), ('Zara', 23), ('Rosalyn', 26), ('Risa', 24), ('Benny', 28), ('Juan', 33), ('Natalie', 25)]

    # numbers acending numerically
    print(sorted(numbers))
    print()

    # people alphabetically by name
    print(sorted(people, key=lambda name: name[0]))
    print()
    
    # people decending by age, same age sorted alphabetically
    print(sorted(people, key=lambda age: (-age[1], age[0])))

if __name__ == '__main__':
    sorting()