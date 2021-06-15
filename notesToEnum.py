#! python3 

enum = "enum octave {\n"
octaves = "constexpr std::initializer_list<octave> octaves = {"
operator = "inline QDebug operator<< (QDebug dbg, octave o) {\n" \
				"\tswitch (o) {\n"

with open("./notesFrequency.txt","r") as f:
	while l := f.readline():
		frequency = l[:-1].split("\t")
		name = frequency.pop(0)

		for i in range(1,len(frequency)):
			noteName = "note" + name.capitalize().replace("#","d")+str(i-1)
			enum += "\t"+noteName+" = "+str(frequency[i]).replace(",",".").replace(".","")+",\n"
			octaves += noteName +", "
			operator += "\t\tcase "+noteName+": dbg<< \""+noteName+"\"; break;\n"

print(enum[:-2]+"\n};")
print(octaves[:-2]+"};")
print(operator + "\t\tdefault: dbg << int(o); break;\n \t}\n\treturn dbg;\n}")