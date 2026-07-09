// 네트워크 취약점 탐색 시스템

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void web(); // 웹 서버 함수
void login(); // 로그인 서버 함수
void database(); // 데이터베이스 서버 함수

int score=0; // 위험 감지도 점수

int main() // 문제 ->> while 안에 있는 코드가 break에 걸리지 않고 무한 반복으로 출력됨
{
    srand(time(NULL)); // 매번 다른 랜덤값이 나오게 하기 위함

    int choice; // 사용자 입력값
    int web1=0; // 웹 서버 선택 여부 확인 >> 현재 상태 저장
    int login1=0; // 로그인 서버 선택 여부 확인 >> 현재 상태 저장
    int database1=0; // 데이터베이스 서버 선택 여부 확인 >> 현태 상태 저장

    printf("\n===============================\n");
    printf("  네트워크 취약점 탐색 시스템\n");
    printf("===============================\n");
    printf(".\n.\n.\n\n탐색을 시작합니다.\n\n. . .\n\n네트워크 연결 완료!");
    while(1)
    {
        printf("\n\n[서버 선택]");
        printf("\n\n1. 웹 서버\n2. 로그인 서버\n3. 데이터베이스 서버\n4. 탐색 종료");
        printf("\n선택 > ");
        scanf("%d",&choice);
        while(choice<1 || choice>4) // 1,2,3 중 선택하지 않았을 시 다시 입력
        {
            printf("\n\n다시 입력해주세요.\n>");
            scanf("%d",&choice);
        }
        switch(choice)
        {
            case 1:
            if(web1 == 0)
            {
                printf("\n웹 서버로 이동합니다 . . .\n\n");
                web();
                web1++;
            }else
            {
                printf("\n이미 검사한 서버입니다.");
            }
            break;
            case 2:
            if(login1 == 0)
            {
                printf("\n로그인 서버로 이동합니다 . . .\n\n");
                login();
                login1++;
            }else
            {
                printf("\n이미 검사한 서버입니다.");
            }
            break;
            case 3:
            if(database1 == 0)
            {
                printf("\n데이터베이스 서버로 이동합니다 . . .\n\n");
                database();
                database1++;
            }
            break;
            case 4:
            printf("\n탐색을 종료합니다.");
            if(score>=80)
            {
                printf("\n\n현재 위험 점수 %d점입니다.\n보안 등급은 F등급입니다.",score);
            }else if(score>=60)
            {
                printf("\n\n현재 위험 점수 %d점입니다.\n보안 등급은 D등급입니다.",score);
            }else if(score>=40)
            {
                printf("\n\n현재 위험 점수 %d점입니다.\n보안 등급은 C등급입니다.",score);
            }else if(score>0)
            {
                printf("\n\n현재 위험 점수 %d점입니다.\n보안 등급은 B입니다.",score);
            }else
            {
                printf("\n\n현재 위험 점수 %d점입니다.\n보안 등급은 A입니다.",score);
            }
            return 0; // while문을 빠져나오기 위해 main함수 전체 종료
        }
    }
}
void web()
{
    int choice;
    int security=0; // 보안 상태 저장
    printf("[웹 서버 보안 분석]\n\n1. HTTPS 사용 여부 검사\n2. 입력값 검증 검사\n3. 파일 업로드 검사\n> ");
    scanf("%d",&choice);
    while(choice<1 || choice>3) 
    {
        printf("\n\n다시 입력해주세요.\n>");
        scanf("%d",&choice);
    }
    switch(choice)
    {
        case 1:
        printf("\nHTTPS 사용 여부 검사 시작 . . .");
        security = rand()%2; // 어떤 수를 2로 나눴을 때의 나머지는 항상 0이나 1이 나옴 ->> 랜덤 숫자를 뽑고, 나머지만을 가져오기 위함
        if(security==0)
        {
            printf("\n\nHTTPS 미사용 취약점 발견 !");
            score+=10;
            printf("\n\n위험 점수 +10");
        }else
        {
            printf("\n\nHTTPS가 정상적으로 작동되고 있습니다.");
        }
        break;

        case 2:
        printf("\n입력값 검증 검사 시작 . . . ");
        security = rand()%2;
        if(security==0)
        {
            printf("\n\n입력값 검증 부족 취약점 발견 !");
            score+=20;
            printf("\n\n위험 점수 +20");
        }else
        {
            printf("\n\n입력값이 정상적으로 검증되었습니다.");
        }
        break;

        case 3:
        printf("\n파일 업로드 검사 시작 . . .");
        security = rand()%2;
        if(security==0)
        {
            printf("\n\n파일 업로드 취약점 발견 !");
            score+=30;
            printf("\n\n위험 점수 +30");
        }else
        {
            printf("\n\n파일 업로드 보안 설정이 적용되어 있습니다.");
        }
        break;
    }
}
void login()
{
    int choice;
    int security=0;
    printf("[로그인 서버 분석]\n\n1. 비밀번호 검사\n2. 로그인 시도 제한 검사\n3. 2차 인증 검사\n> ");
    scanf("%d",&choice);
    while(choice<1 || choice>3) 
    {
        printf("\n\n다시 입력해주세요.\n>");
        scanf("%d",&choice);
    }
    switch(choice)
    {
        case 1:
        printf("\n비밀번호 검사 시작 . . .");
        security = rand()%2;
        if(security == 0)
        {
            printf("\n\n보안도 낮은 비밀번호 취약점 발견 !");
            score+=10;
            printf("\n\n위험 점수 +10");
        }else
        {
            printf("\n\n비밀번호 검사를 통과하였습니다.");
        }
        break;

        case 2:
        printf("\n로그인 제한 검사 시작 . . .");
        security = rand()%2;
        if(security == 0)
        {
            printf("\n\n로그인 시도 제한 없음\n무차별 대입 공격 위험 발견 !");
            score+=20;
            printf("\n\n위험 점수 +20");
        }else
        {
            printf("\n\n로그인 실패 제한 기능이 적용되어 있습니다.");
        }
        break;

        case 3:
        printf("\n2차 인증 검사 시작 . . .");
        security = rand()%2;
        if(security == 0)
        {
            printf("\n\n2차 인증 방식 적용 안 됨\n인증 취약점 발견 !");
            score+=30;
            printf("\n\n위험 점수 +30");
        }else
        {
            printf("\n\n2차 인증 방식이 적용되어 있습니다.");
        }
        break;
    }
}
void database()
{
    int choice;
    int security=0;
    printf("[데이터베이스 서버 분석]\n\n1. 접근 권한 검사\n2. 데이터 암호화 검사\n3. 백업 보안 검사\n>");
    scanf("%d",&choice);
    while(choice<1 || choice>3) 
    {
        printf("\n\n다시 입력해주세요.\n>");
        scanf("%d",&choice);
    }
    switch(choice)
    {
        case 1:
        printf("\n접근 권한 검사 시작 . . .");
        security=rand()%2;
        if(security == 0)
        {
            printf("\n\n권한 관리 취약점 발견 !");
            score+=10;
            printf("\n\n위험 점수 +10");
        }else
        {
            printf("\n\n접근 권한 설정이 정상입니다.");
        }
        break;

        case 2:
        printf("\n데이터 암호화 검사 시작 . . .");
        security=rand()%2;
        if(security == 0)
        {
            printf("\n\n데이터 암호화 미적용\n정보 노출 위험 발견 !");
            score+=20;
            printf("\n\n위험 점수 +20");
        }else
        {
            printf("\n\n데이터 암호화가 적용되어 있습니다.");
        }
        break;

        case 3:
        printf("\n백업 보안 검사 시작 . . .");
        security=rand()%2;
        if(security == 0)
        {
            printf("\n\n백업 데이터 보안 부족\n취약점 발견 !");
            score+=30;
            printf("\n\n위험 점수 +30");
        }else
        {
            printf("\n\n백업 보안이 안전하게 관리되고 있습니다.");
        }
        break;
    }
}
