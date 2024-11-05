from cs50 import get_string
import string

def words(text):

    return (len(text.split()))

def letters(text):
    for punct in string.punctuation:
        text = text.replace(punct, "").replace(" ", "")
    return len(text)

def sentences(text):
    count = 0;
    for c in range(len(text)):
        if text[c] == '.' or text[c] == '!' or text[c] == '?':
            count = count + 1;
    return count

text = get_string("Text: ")

letterCount = int(letters(text))
wordCount = int(words(text))
sentencesCount = int(sentences(text))


print("W = ", wordCount)
print("L = ", letterCount)
print("s = ", sentencesCount)

L = float(100.0 * letterCount / wordCount);
S = float(100.0 * sentencesCount / wordCount);

grade = float(0.0588 * L - 0.296 * S - 15.8);

rounding = int(round(grade));

if rounding < 1:
    print("Before Grade 1")

elif rounding >= 16:
    print("Grade 16+")

else:
    print("Grade ", rounding)



