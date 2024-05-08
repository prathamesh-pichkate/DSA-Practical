class Set:
    def __init__(self):
        self.elements = []

    def add(self, newElement):
        if newElement not in self.elements:
            self.elements.append(newElement)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def contains(self, element_set):
        return all(element in self.elements for element in element_set)

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def intersection(self, otherSet):
        intersectionSet = Set()
        for element in self.elements:
            if otherSet.contains([element]):
                intersectionSet.add(element)
        return intersectionSet

    def union(self, otherSet):
        unionSet = Set()
        unionSet.elements = self.elements.copy()
        for element in otherSet.elements:
            unionSet.add(element)
        return unionSet

    def difference(self, otherSet):
        differenceSet = Set()
        for element in self.elements:
            if not otherSet.contains([element]):
                differenceSet.add(element)
        return differenceSet

    def subset(self, otherSet):
        for element in self.elements:
            if not otherSet.contains([element]):
                return False
        return True

# Example usage:
set1 = Set()
n = int(input("Enter the number of elements for set 1: "))
print("Enter elements for set 1: ")
for _ in range(n):
    element = input()
    set1.add(element)

set2 = Set()
m = int(input("Enter the number of elements for set 2: "))
print("Enter elements for set 2: ")
for _ in range(m):
    element = input()
    set2.add(element)
print("Set 1:", list(set1.iterator()))
print("Set 2:", list(set2.iterator()))

print("Intersection:", list(set1.intersection(set2).iterator()))
print("Union:", list(set1.union(set2).iterator()))
print("Difference (Set 1 - Set 2):", list(set1.difference(set2).iterator()))

print("Set 1 is a subset of Set 2:", set1.subset(set2))

# Removing an element from set1
element_to_remove = input("Enter an element to remove from set 1: ")
set1.remove(element_to_remove)
print("Set 1 after removing", element_to_remove + ":", list(set1.iterator()))

# Size of set1
print("Size of Set 1:", set1.size())

# Checking if a specific set is a subset of another set
print("Is Set 2 a subset of Set 1:", set2.subset(set1))


#contain 
print("Set 1 contains '1':", set1.contains('1'))
