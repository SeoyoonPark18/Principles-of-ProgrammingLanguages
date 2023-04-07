import Data.List

numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
people = [("Hal", 20), ("Susann", 31), ("Dwight", 19), ("Kassandra", 21), ("Lawrence", 25), ("Cindy", 22), ("Cory", 27), ("Mac", 19), ("Romana", 27), ("Doretha", 32), ("Danna", 20), ("Zara", 23), ("Rosalyn", 26), ("Risa", 24), ("Benny", 28), ("Juan", 33), ("Natalie", 25)]

main :: IO()
main = do
  -- sort :: Ord a => [a] -> [a]
  print(sort numbers)
  putStrLn ""
  -- sortOn :: Ord b => (a -> b) -> [a] -> [a]
  -- fst :: (a, b) -> a
  -- Takes in a list of tuples and calls sortOn the fst (first) argument
  print(sortOn fst people)
  putStrLn ""
  -- Take in a list of tuples and pass it into \(name, age), then call sortOn \(name, age) and return it with descending age, then sorts by name if age is the same
  print(sortOn (\(name, age) -> (-age, name)) people)