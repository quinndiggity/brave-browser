/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_BRAVE_STATS_UPDATER_PARAMS_H_
#define BRAVE_BROWSER_BRAVE_STATS_UPDATER_PARAMS_H_

#include <string>

#include "base/macros.h"

namespace base {
class Time;
}

namespace brave {

class BraveStatsUpdaterParams {
 public:
  BraveStatsUpdaterParams();
  ~BraveStatsUpdaterParams();

  std::string GetDailyParam() const;
  std::string GetWeeklyParam() const;
  std::string GetMonthlyParam() const;
  std::string GetFirstCheckMadeParam() const;
  std::string GetWeekOfInstallationParam() const;

 private:
  std::string today_ymd_;
  int today_woy_;
  int today_month_;
  std::string last_check_ymd_;
  int last_check_woy_;
  int last_check_month_;
  bool first_check_made_;
  std::string week_of_installation_;

  void LoadPrefs();
  void SavePrefs();

  std::string BooleanToString(bool bool_value) const;

  std::string GetDateAsYMD(const base::Time& time) const;
  std::string GetCurrentDateAsYMD() const;
  std::string GetLastMondayAsYMD() const;
  int GetCurrentMonth() const;
  int GetCurrentISOWeekNumber() const;

  DISALLOW_COPY_AND_ASSIGN(BraveStatsUpdaterParams);
};

}  // namespace brave

#endif  // BRAVE_BROWSER_BRAVE_STATS_UPDATER_PARAMS_H_
