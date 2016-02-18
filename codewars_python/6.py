def spin_words(sentence):
    # Your code goes here
    word_list = sentence.split();
    print(word_list);
    ret_list=[];
    for word in word_list:
        print(word)
        if len(word) > 4:
            word=word[::-1];
        print(word)
        ret_list.append(word);
    print(ret_list);
    return " ".join(ret_list);

spin_words("Welcome");
