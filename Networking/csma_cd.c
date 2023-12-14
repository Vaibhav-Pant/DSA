    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <string.h>
    #include <sys/time.h>
    int x = 0;
    void capture()
    {
        exit(0);
    }
    int get()
    {
        return x;
    }
    void put()
    {
        x++;
    }
    void node(char *p)
    {
        int name;
        int seq1, seq2, i = 0;
        long int t;
        struct timeval tv;
        struct timezonetz;
        name = atoi(p);
        while (1)
        {
            seq1 = get();
            seq2 = get();
            if (seq1 == seq2)
            {
                put();
                seq1 = get();
                printf("station %d transmitting frame %d\n", name, ++i);
                sleep(3);
                seq2 = get();
                if (seq1 != seq2)
                {
                    printf("station %d collision occured %d \n", name, i--);
                    sleep(3);
                }
                else
                {
                    printf("station %d complete\n", name, i);
                }
            }
            sleep(3);
        }
    }
    main()
    {
        pthread_t t1, t2, t3;
        pthread_create(&t1, 0, (void *)node, "1");
        pthread_create(&t2, 0, (void *)node, "2");
        pthread_create(&t3, 0, (void *)node, "3");
        while (1)
            ;
    }
