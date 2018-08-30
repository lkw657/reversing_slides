# Reversing

These are the slides and supporting materials I used for a couple of presentations on basics of reverse engineering. I am not sure how useful this would be without the presentation (which wasn't recorded). But I will put it here in case it is. I'd like to thank Leeky, C_Sto, kronicd and curryhacker for providing feedback on my slides as well as dtm for making NoREPls and \_py for collecting the crackmes in the crackmes subdirectory.

Not all of the binaries in this repo are my own, and so not covered by the license. I obtained the binaries from http://skidophrenia.ctfd.io which no longer exists, but was a nice selection of binaries for beginners. I do not know any more about where these binaries originated other than what is stated in the binary. If you are one of the authors and would like it to be removed or a link given to your site, please contact me (opening an issue should work).

While I mostly focused on linux, you can get some good crackmes for windows from [this](https://0x00sec.org/t/crackme-norepls-part-0) series by dtm.

### Contents
* re.pdf
    presentation slides
* crackmes
    Some crackmes to try reversing
    None of these are mine, see above.
* codes
    Folder with c code compiled for 32 and 64 bit
    You can add any c files to this directory and use make to compile for both
    This was mostly for looking at the difference between 32 and 64 bit function calling conventions, but I ended up using the same directory and makefile for other examples
* anti
    Examples of techniques to try to make reversing harder
    These should line up with the slides, the name of the binary is in parentheses in the slide title.
    See the Makefile for the compiler flags used for each source
    Some of these are based on the book Programming Linux: Anti-Reversing Techniques which you can pay what you want for (>=0) [here](https://leanpub.com/anti-reverse-engineering-linux)


