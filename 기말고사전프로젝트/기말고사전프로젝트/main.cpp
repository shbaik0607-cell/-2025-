#include <stdio.h>
#include <math.h>

// 중력 가속도 G와 PI 값을 상수 정의
#define G 9.81              // 중력 가속도 (m/s^2)
#define PI 3.141592653589793 // 원주율 PI
#define DT 0.01             // 시간 간격 (dt = 0.01 sec)


double deg_to_rad(double deg) {
    // 라디안 = 각도 * (PI / 180) 공식 적용
    return deg * (PI / 180.0);
}


void calculate_results(double v0, double theta_rad, double* results) {
    double t = 0.0;     // 현재 시간
    double x = 0.0;     // 현재 수평 위치
    double y = 0.0;     // 현재 수직 위치
    double max_h = 0.0; // 최고 도달 높이
    double max_r = 0.0; // 최대 수평 사거리

    // 초기 속도 성분 계산
    double vx = v0 * cos(theta_rad); // 수평 속도 (상수)
    double vy = v0 * sin(theta_rad); // 초기 수직 속도

    // 시뮬레이션 루프: y가 0 이하로 떨어질 때까지 반복
    while (y >= 0.0 || t == 0.0) {
        // x(t) = vx * t
        x = vx * t;
        // y(t) = (v0 * sin(theta)) * t - 0.5 * G * t^2
        y = (vy * t) - (0.5 * G * t * t);

        // 1. 최고 도달 높이 갱신
        if (y > max_h) {
            max_h = y;
        }

        // 2. 최대 수평 거리 갱신 (매 순간 x는 증가하므로, 착지 직전의 x가 최대 거리)
        max_r = x;

       
        if (y < 0.0) {
            
            double t_prev = t - DT;
            double y_prev = (vy * t_prev) - (0.5 * G * t_prev * t_prev);

            // 보간된 시간 간격 (착지 순간의 시간)
            double dt_interp = DT * y_prev / (y_prev - y);

            // 최종 체공 시간
            results[0] = t_prev + dt_interp;

            // 착지 시의 최대 수평 도달 거리도 보정된 시간으로 다시 계산
            double final_x = vx * results[0];
            results[2] = final_x;

            break; // 착지했으므로 루프 종료
        }

        // 시간 증가
        t += DT;

        // 안전 장치: 무한 루프 방지 (예: 100초 초과 시 강제 종료)
        if (t > 100.0) {
            printf("경고: 시뮬레이션 시간이 100초를 초과했습니다. 계산 오류 가능성.\n");
            results[0] = 0.0; // 오류 값 설정
            results[1] = 0.0;
            results[2] = 0.0;
            return;
        }
    }

    // 결과 배열에 최고 높이 저장
    results[1] = max_h;
}


int main() {
    // 주어진 초기 조건
    double initial_velocity = 15.0; // v0 = 15 m/s
    double angle_deg = 75.0;        // theta = 75 deg

    // 결과를 저장할 배열: [0] 체공시간, [1] 최고 높이, [2] 최대 거리
    // * 배열/포인터 사용 요구사항 충족
    double results_array[3];

    printf("--- 소형 물로켓 2차원 포물체 운동 시뮬레이션 ---\n");
    printf("초기 속도 (v0): %.2lf m/s\n", initial_velocity);
    printf("발사 각도 (theta): %.0lf 도\n", angle_deg);
    printf("중력 가속도 (g): %.2lf m/s^2\n", G);
    printf("시간 간격 (dt): %.2lf 초\n", DT);
    printf("---------------------------------------------------\n");

    // 1. 각도를 라디안으로 변환
    double angle_rad = deg_to_rad(angle_deg);

    // 2. 계산 함수 호출 (배열의 첫 주소를 포인터로 전달)
    calculate_results(initial_velocity, angle_rad, results_array);

    // 3. 최종 결과 출력
    if (results_array[0] > 0.0) {
        printf("\n[최종 결과]\n");
        printf("1. 체공 시간 (T): %.4lf 초\n", results_array[0]);
        printf("2. 최고 도달 높이 (H): %.4lf 미터\n", results_array[1]);
        printf("3. 수평 사거리 (R): %.4lf 미터\n", results_array[2]);
    }
    else {
        printf("\n계산 실패 또는 오류가 발생했습니다.\n");
    }

    return 0;
}