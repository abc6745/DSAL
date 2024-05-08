def accept_list1(A):
	n=int(input("How many elements you want in list?"))
	for i in range(n):
		ele=int(input("Enter elements"))
		A.append(ele)
	print("List 1: ",A)
	return

def add_ele(A):
	x=int(input("Enter element to append in list"))
	A.append(x)
	print("List 1: ",A)
	return

def delete_ele(A):
	z=int(input("Enter element to be deleted"))
	A.remove(z)
	print("List after deleting element is: ")
	print("List 1: ",A)
	return

def contain(A):
	y=int(input("Enter element to be searched"))
	if y in A:
		print("List contain element ",y)
	else:
		print("List does not contain element ",y)
	return

def accept_list2(B):
	n=int(input("How many elements you want in list?")) 
	for i in range(n):
		ele=int(input("Enter elements"))
		B.append(ele)
	print("List 2: ",B)
	return

def union(A,B,C):
	C=[]
	C.extend(A)
	for i in B:
		if i not in A:
			C.append(i)
	print("Union of two list is : ",C)
	return

def intersection(A,B,C):
	C=[]
	for i in A:
		for j in B:
			if i==j:
				C.append(i)
	print("Intersection of two list is: ",C)
	return

def diff(A,B,C):
	C=[]
	for i in A:
		if i not in B:
			C.append(i)
	print("Difference of two list is: ",C)
	return

def subset(A,B):
	x=len(A)
	y=len(B)
	if x>=y:
		sub= all(i in A for i in B)
		if sub:
			print("B is subset of A")
		else:
			print("B is not subset of A")
	else:
		print("Not a subset")
	return

def proper_sub(A,B):
	if sorted(A)==sorted(B):
		print("Proper subset")
	else:
		print("Not a Proper subset")
	return
def main():
	A=[]
	B=[]
	C=[]
	while True:
		print("1.Create list")
		print("2.Add element")
		print("3.Delete element")
		print("4.Search element")
		print("5.Create list 2")
		print("6.Union")
		print("7.Intersection")
		print("8.Differnce")
		print("9.Subset")
		print("10.Proper subset")
		print("11.Exit")
		ch=(int(input("Enter your choice")))
		if ch==1:
			accept_list1(A)
			
		elif ch==2:
			add_ele(A)
			
		elif ch==3:
			delete_ele(A)
			
		elif ch==4:
			contain(A)
			
		elif ch==5:
			accept_list2(B)
			
		elif ch==6:
			union(A,B,C)
			
		elif ch==7:
			intersection(A,B,C)
			
		elif ch==8:
			diff(A,B,C)
			
		elif ch==9:
			subset(A,B)
			
		elif ch==10:
			proper_sub(A,B)
			
		elif ch==11:
			quit()
			break;
		else:
			print("Wrong choice entered")
			
main()

















