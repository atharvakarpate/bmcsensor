#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

int msleep(unsigned int tms) {
  return usleep(tms * 1000);
}

int main(){

long start,end, interval;

start =  current_timestamp();
end = start + 10000;
printf("start %ld end %ld \n",start, end);

while ( current_timestamp() < end){

interval = 500;

msleep(interval -  current_timestamp()%interval);

printf("%lld \n",  current_timestamp());
}

}
