# PS-study
---
프로그래밍 문제 풀이 모음

주로 C, C++로 풀이할 예정

- #### 관리하고 있는 문제
  - 2019-summer-academy : 2019 청년취업 아카데미
  - BOJ : Baekjoon Online Judge
  - Programmers : 프로그래머스, 레벨별로 풀이중, 심플한 문제는 추가 X
  
- #### 코드별 테스트 방법

  - **2019-summer-academy**
    ```c 
    <test.h>
    
    #pragma once
    #define PNUM [FileName]
    ```
    FileName은 .c 를 제외한 파일명이다.
    
    문제번호가 파일이름과 동일함  
    
  - **BOJ**
    ```c 
    <test-boj.h>
    
    #pragma once
    #define PNUM [ProblemNumber]
    ```
    ProblemNumber는 백준 문제번호를 뜻한다.
    
    파일명도 동일하게 되어있다.  
    
  - **Programmers**
     ```c 
    <test-prog.h>
    
    #pragma once
    #define PNUM [FolderName-FileName]
    ```
    FolderName은 레벨이름이다. ex) lv01, lv02, ...
    
    FileName은 푼 문제 순서대로 지었다.
    
    
각 파일 상단에 ```#if (PNUM == [OOOO])``` OOOO 부분을 복사 붙여넣기 해도 된다.
