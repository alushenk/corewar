.comment "segodnya v zavtrishniy den"
.name       "Klitschko"  


myname:      st r1, 1
          
preparing:      st r2, -8
                ldi %0, %-9, r1
        
                  st r1, 61
                  st r1, 75
                  st r1, 75
                  st r1, 75
                  st r1, 75
                  st r1, 75
                  st r1, 75 
                  st r1, 75 
                  st r1, 75 
                  st r1, 75 
                  st r1, 75 
                  st r1, 75    
main:             live %1
                
                  and r3, %0, r3
                  fork %:alive
                  zjmp %:main
                
alive:  live %1
        live %1
        live %1
        live %1
        live %1
        live %1
        live %1
        live %1
        live %1
        live %1
        live %1
        zjmp %:alive
