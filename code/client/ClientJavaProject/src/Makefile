MY_PATH   = ~/User-installed/jdk-17.0.6+10/bin/
JC        = $(MY_PATH)javac
JVM       = $(MY_PATH)java 
JFLAGS    = -g

CLASSES = Client.java MainFrame.java
MAIN    = Client

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

default: classes

classes: $(CLASSES:.java=.class)

run: $(MAIN).class
	$(JVM) $(MAIN)

clean:
	rm -f *.class
.PHONY : clean
