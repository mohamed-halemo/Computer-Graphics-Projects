##Name:Mohamed AbdelHalem Abdallah
ID:1180182
```
##I took a 4 screen shots showing the fingers made as the picture in the tuturoail also some of
the screens shows how the fingers and and upper fingers move together
also i did fix the angels to make it as reialstic as possible by making the finger moves until
a certain angel then stop movement and the other direction makes it goes back.
```
##Example of how i managed angels:
  shoulder = (shoulder + 5); //here we keep moving it 
        if (shoulder > 95) { //once  reached more than 90 we put it to 90 and stop the movement
            shoulder = (shoulder - 5);
            break;
        }


###problem faced:the problem i faced is making the fingers move together as each one moved alone
but one of my friends Mostafa Neddal told me a hint to use push and pop before each finger
and it did work and i understood why becuase each one took the previous one's translating 
and push and pop made each one alone taking just elbow and shoulder
```

###Implementation: each finger is implementation is same but we change the first translate's
coordinates to make them well positioned

glPushMatrix();
    //Draw finger flang 1 
    glTranslatef(1.0, -0.25, 0.0);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //////
    

    //Draw finger flang 1 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();


Thanks!!
