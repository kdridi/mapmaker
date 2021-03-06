/*
 * Copyright (c) 2014, Julien Bernard
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <mm/colormap.h>

#include <iostream>

namespace mm {

  void colormap::output_to_ppm(std::ostream& file) const {
    file << "P3\n";
    file << this->width() << ' ' << this->height() << '\n';
    file << static_cast<unsigned>(mm::color::max) << '\n';

    for (size_type y = 0; y < this->height(); ++y) {
      for (size_type x = 0; x < this->width(); ++x) {
        auto c = this->get(x, y);

        file << static_cast<unsigned>(c.red_channel()) << ' '
            << static_cast<unsigned>(c.green_channel()) << ' '
            << static_cast<unsigned>(c.blue_channel()) << ' ';
      }

      file << '\n';
    }
  }

}
