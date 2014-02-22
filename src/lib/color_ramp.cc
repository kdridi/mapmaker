#include <mm/color_ramp.h>

#include <mm/curve.h>

namespace mm {

  static color lerp(const color& lhs, const color& rhs, double t) {
    return {
      lerp(lhs.red_channel(), rhs.red_channel(), t),
      lerp(lhs.green_channel(), rhs.green_channel(), t),
      lerp(lhs.blue_channel(), rhs.blue_channel(), t),
      lerp(lhs.alpha_channel(), rhs.alpha_channel(), t)
    };
  }

  void color_ramp::add_color_stop(double offset, const color& c) {
    if (empty()) {
      m_min = offset;
      m_max = offset;
    } else {
      if (offset < m_min) {
        m_min = offset;
      }

      if (offset > m_max) {
        m_max = offset;
      }
    }

    m_map.emplace(offset, c);
  }

  color color_ramp::get_color(double offset) const {
    if (offset < m_min || offset > m_max) {
      return color();
    }

    color c1, c2;
    double t1 = 0.0;
    double t2 = 0.0;
    for (auto value : m_map) {
      if (value.first <= offset) {
        t1 = value.first;
        c1 = value.second;
      } else {
        t2 = value.first;
        c2 = value.second;
        break;
      }
    }

    return lerp(c1, c2, (offset - t1) / (t2 - t1));
  }

}
