-- quickSort [5, 3, 1, 2, 6, 4, 10, 20, 32, 15]
-- quickSort []
-- quickSort [-1, 5, 7, 12, 3, -5, -19, 15]

-- quickSort
quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (pivot : xs) = (quickSort lessThan) ++ [pivot] ++ (quickSort greaterThan)
  where
    lessThan = filter (< pivot) xs
    greaterThan = filter (>= pivot) xs

-- mergeSort [1, 3, 5, 7, 8, 9, 12, 2, 4, 6, 10, 11, 15, 19]
-- mergeSort []
-- mergeSort [-1, 5, 7, 12, 3, -5, -19, 15]

-- mergeSort
mergeSort :: (Ord a) => [a] -> [a]
mergeSort [a] = [a]
mergeSort [] = []
mergeSort a =
  merge (mergeSort firstFew) (mergeSort lastFew)
    where firstFew = take ((length a) `div` 2) a
          lastFew = drop ((length a) `div` 2) a
          -- Expects a and b to already be sorted

merge :: (Ord a) => [a] -> [a] -> [a]
merge a [] = a
merge [] b = b
merge (a:as) (b:bs)
  | a < b     = a:(merge as (b:bs))
  | otherwise = b:(merge (a:as) bs)

