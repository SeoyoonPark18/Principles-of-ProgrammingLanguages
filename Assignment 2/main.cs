using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  public static void Main (string[] args) {

    float[] numbers = { 645.41f, 37.59f, 76.41f, 5.31f, -34.23f, 1.11f, 1.10f, 23.46f, 635.47f, -876.32f, 467.83f, 62.25f };
    List<KeyValuePair<string, int>> people = new List<KeyValuePair<string, int>>() {
            new KeyValuePair<string, int>("Hal", 20),
            new KeyValuePair<string, int>("Susann", 31),
            new KeyValuePair<string, int>("Dwight", 19),
            new KeyValuePair<string, int>("Kassandra", 21),
            new KeyValuePair<string, int>("Lawrence", 25),
            new KeyValuePair<string, int>("Cindy", 22),
            new KeyValuePair<string, int>("Cory", 27),
            new KeyValuePair<string, int>("Mac", 19),
            new KeyValuePair<string, int>("Romana", 27),
            new KeyValuePair<string, int>("Doretha", 32),
            new KeyValuePair<string, int>("Danna", 20),
            new KeyValuePair<string, int>("Zara", 23),
            new KeyValuePair<string, int>("Rosalyn", 26),
            new KeyValuePair<string, int>("Risa", 24),
            new KeyValuePair<string, int>("Benny", 28),
            new KeyValuePair<string, int>("Juan", 33),
            new KeyValuePair<string, int>("Natalie", 25)
        };

    // Array.Sort<float>(numbers);
    var res1 = numbers.OrderBy(f => f);
    Console.Write("Sorting numbers by numerical value\n");
    foreach (float num in res1)
        {
            Console.WriteLine(num);
        }

    var res2 = people.OrderBy(x => x.Key);
    Console.Write("\n\nSorting people alphabetically\n");
    foreach (KeyValuePair<string, int> person in res2) 
    {
      Console.WriteLine(person.Key + ", " + person.Value);
    }

    var sortedPeople = people.OrderByDescending(x => x.Value).ThenBy(x => x.Key);
    Console.Write("\n\nSorting people descending by age, then alphabetically by name.\n");
    foreach (var person in sortedPeople)
{
    Console.WriteLine($"{person.Key}, {person.Value}");
}
    
  }
}