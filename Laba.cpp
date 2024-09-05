#include <stdio.h>
#include <math.h>
const int Amount_exp_vals = 4000;
const int Temp_size = 4;

int main (){
    int temp[Temp_size] = {10, 20, 40, 80};
    int n_i = 0;
    int exp_val [Amount_exp_vals/10] = {};
    for(int t = 0; t<Temp_size; t++){
        FILE * file = fopen("exp.txt", "r");
        int sum_exp_val = 0;
        for (int i = 0; i<Amount_exp_vals/temp[t]; i++){
            int sum_n_i = 0;
            for(int j = temp[t]*i; j<temp[t]*(i+1); j++){

                fscanf(file, "%d", &n_i);
                sum_n_i += n_i;
            }
            exp_val[i] = sum_n_i;

        }
        for (int i = 0; i<Amount_exp_vals/temp[t]; i++){

            sum_exp_val += exp_val[i];

        }
        double choose_n = ((double)sum_exp_val)/((double)(Amount_exp_vals/temp[t]));
        double sigm_q = 0;
        for (int i = 0; i<(Amount_exp_vals/temp[t]); i++){
            sigm_q += (exp_val[i]-choose_n)*(exp_val[i]-choose_n);
        }
        sigm_q = sigm_q/(Amount_exp_vals/temp[t]);
        sigm_q = sqrt(sigm_q);
        double std_err_av_n = sigm_q/sqrt(Amount_exp_vals/temp[t]);
        double epsilon = std_err_av_n*100.0/choose_n;
        printf("sigm_q = %lf, sum_exp_val = %d, "
        "n(t = %d) = %lf +- %lf, E = %lf %% \n",
                   sigm_q, sum_exp_val, temp[t], choose_n, std_err_av_n,epsilon);
    }
}
