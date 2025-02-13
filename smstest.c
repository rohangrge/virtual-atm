#include<stdio.h>
#include<string.h>
#include"curl.h"
#include<stdbool.h>
//int twilio_send_message(*char,*char,*char,*char,*char,*char,bool);

int twilio_send_message(char *account_sid,
                        char *auth_token,
                        char *message,
                        char *from_number,
                        char *to_number,
                        char *picture_url,
                        bool verbose)
{

        // See: https://www.twilio.com/docs/api/rest/sending-messages for
        // information on Twilio body size limits.
        if (strlen(message) > 1600) {
            fprintf(stderr, "SMS send failed.\n"
                    "Message body must be less than 1601 characters.\n"
                    "The message had %zu characters.\n", strlen(message));
            return -1;
        }

        CURL *curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();

        char url[MAX_TWILIO_MESSAGE_SIZE];
        snprintf(url,
                 sizeof(url),
                 "%s%s%s",
                 "https://api.twilio.com/2010-04-01/Accounts/",
                 account_sid,
                 "/Messages");

        char parameters[MAX_TWILIO_MESSAGE_SIZE];
        if (!picture_url) {
            snprintf(parameters,
                     sizeof(parameters),
                     "%s%s%s%s%s%s",
                     "To=",
                     to_number,
                     "&From=",
                     from_number,
                     "&Body=",
                     message);
        } else {
            snprintf(parameters,
                     sizeof(parameters),
                     "%s%s%s%s%s%s%s%s",
                     "To=",
                     to_number,
                     "&From=",
                     from_number,
                     "&Body=",
                     message,
                     "&MediaUrl=",
                     picture_url);
        }


        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameters);
        curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token);

        if (!verbose) {
                curl_easy_setopt(curl, 
                                 CURLOPT_WRITEFUNCTION, 
                                 _twilio_null_write);
        }

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        long http_code = 0;
        curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);

        if (res != CURLE_OK) {
                if (verbose) {
                        fprintf(stderr,
                                "SMS send failed: %s.\n",
                                curl_easy_strerror(res));
                }
                return -1;
        } else if (http_code != 200 && http_code != 201) {
                if (verbose) {
                        fprintf(stderr,
                                "SMS send failed, HTTP Status Code: %ld.\n",
                                http_code);
                }
                return -1;
        } else {
                if (verbose) {
                        fprintf(stderr,
                                "SMS sent successfully!\n");
                }
                return 0;
        }

}
int main(void)
{
    char a[30];//'AC1747455ff6efa95d82be4cbe09eb6c02';
    scanf("%s",a);
    char b[30];//='c016829c94ff441025110d22acec35f0';
    scanf("%s",b);
    char b1[30];
    scanf("%s",b1);
    char c[30];//='+12564148265';
    scanf("%s",c);
    char d[30];//='+919481733683';
    scanf("%s",d);
    char e[30];
    scanf("%s",e);
    bool f=true;
    twilio_send_message(*a,*b,*b1,*c,*d,*e,f);
}