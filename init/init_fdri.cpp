/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>

#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    std::ifstream fin;
    std::string buf;
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    fin.open("/proc/app_info", std::ios::in);
    if (!fin)
        return;

    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
    fin.close();

    /* FDR-A01L */
    if (buf.find("FDR-A01L") != std::string::npos) {
        property_set("ro.product.model", "FDR-A01L");
        property_set("ro.product.device", "FDR-A01L");
        property_set("ro.build.product", "FDR-A01L");
        property_set("persist.radio.multisim.config", "dsds");
    }
    /* FDR-A01W */
    else if (buf.find("FDR-A01W") != std::string::npos) {
        property_set("ro.product.model", "FDR-A01W");
        property_set("ro.product.device", "FDR-A01W");
        property_set("ro.build.product", "FDR-A01W");
    }
    /* FDR-A03L */
    else if (buf.find("FDR-A03L") != std::string::npos) {
        property_set("ro.product.model", "FDR-A03L");
        property_set("ro.product.device", "FDR-A03L");
        property_set("ro.build.product", "FDR-A03L");
        property_set("persist.radio.multisim.config", "dsds");
    }
    /* FDR-A04L */
    else if (buf.find("FDR-A04L") != std::string::npos) {
        property_set("ro.product.model", "FDR-A04L");
        property_set("ro.product.device", "FDR-A04L");
        property_set("ro.build.product", "FDR-A04L");
        property_set("persist.radio.multisim.config", "dsds");
    }
    /* FDR-A05L */
    else if (buf.find("FDR-A05L") != std::string::npos) {
        property_set("ro.product.model", "FDR-A05L");
        property_set("ro.product.device", "FDR-A05L");
        property_set("ro.build.product", "FDR-A05L");
    }
}
