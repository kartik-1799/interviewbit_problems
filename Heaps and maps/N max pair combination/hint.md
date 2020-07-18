sort this arrays.
Choose last elements of the 2 arrays and as greatest of all must be in the ans.
Store these last index ,mark them visited, and check for elements having index {n-2, m-1} and {n-1, m-2}.//n & m respectively are size of arrays.
mark them visited, according to their sum store sum & index values them, put maximum sum of those 2 in the  array, 
For the index of maximum of 2, similarly find for index {x-1, y} & {x, y-1}.
mark them visited, according to their sum and previously left sum store those sum and index values, put maximum sum and repeat this step until k.
