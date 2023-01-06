#include "test_runner.h"

#include "config.h" //in header file...

int before_test() {

}

int after_test() {

}

//--------------------

when_testing("funtion open_config() with arguments x y and z...") {
   it_should("spawn an ini text file in append mode.") {
      ...
      ...
   }
}

when_testing("function log_info() with output to LOG.FILE...") {
    it_should("exist in the logfile generated as log.txt") {
      ...
      ...
    }
}
