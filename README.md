# PS-study
---
프로그래밍 문제 풀이 모음

주로 ```C, C++```로 풀이할 예정

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
    <br>
    
  - **BOJ**
    ```c 
    <test-boj.h>
    
    #pragma once
    #define PNUM [ProblemNumber]
    ```
    ProblemNumber는 백준 문제번호를 뜻한다.
    
    파일명도 동일하게 되어있다.
    <br>
    
  - **Programmers**
     ```c 
    <test-prog.h>
    
    #pragma once
    #define PNUM [FolderName-FileName]
    ```
    FolderName은 레벨이름이다. ex) lv01, lv02, ...
    
    FileName은 푼 문제 순서대로 지었다.
    <br>
    
    
각 파일 상단에 ```#if (PNUM == [OOOO])``` OOOO 부분을 복사 붙여넣기 해도 된다.

---

#### (관리 참고용) 커밋명 규칙

[5f32fe1](https://github.com/WonHyun/PS-study/commit/5f32fe1a16e3f7a2086c8d015761505d15ef4da5) 이후 부터 적용한다.

+ ###### 2019-summer-academy
  + **수업과제**
    ``` 
    sub [과제번호] [작업내용]
    ```
  + **수업진도**
    ```
    study [ds | algo] [작업내용]
    ```
    ds : Data Structure, algo : Algorithm
    추후에 다른 것이 추가될 수 있음

+ ###### BOJ
  ```
  boj [문제번호] [작업내용]
  ```
  작업내용이 단순 문제 추가일 경우 문제명을 기록
+ ###### Programmers
  ```
  prog [lv명]-[문제번호] [작업내용]
  ```
  작업내용의 경우 boj와 동일하게 취급
