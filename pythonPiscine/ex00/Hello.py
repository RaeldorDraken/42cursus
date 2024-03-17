ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}

#my code here

index = 0
while index < len(ft_list) - 1:
	index += 1

ft_list[index] = " world!"

index = 0
while index < len(ft_tuple) - 1:
	index += 1

ft_tuple = list(ft_tuple)
ft_tuple[index] = " Spain!"
ft_tuple = tuple(ft_tuple)

#end of my code

print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)