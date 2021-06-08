#! python3 

with open("./notesFrequency.txt","r") as f:
	while l := f.readline():
		frequency = l[:-1].split("\t")
		name = frequency.pop(0)

		for i in range(1,len(frequency)):
			print("note"+name.capitalize().replace("#","d")+str(i-1),"=",str(frequency[i]).replace(",",".").replace(".","")+",")
