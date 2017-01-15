/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#pragma once

#include <folly/FBString.h>
#include <boost/algorithm/string.hpp>
#include <folly/Portability.h>
#include <folly/Conv.h>
//#include <nc/config.h>
using namespace folly;
using namespace std;

namespace nc {

class Branding {
    fbstring applicationName_;
      fbstring applicationVersion_;
      fbstring organizationDomain_;
      fbstring organizationName_;
      fbstring licenseName_;
      fbstring licenseUrl_;
      fbstring reportBugsTo_;

public:
    const   fbstring &applicationName() const { return applicationName_; }
    void setApplicationName(  fbstring name) { applicationName_ = std::move(name); }

    const   fbstring &applicationVersion() const { return applicationVersion_; }
    void setApplicationVersion(  fbstring version) { applicationVersion_ = std::move(version); }

    const   fbstring &organizationDomain() const { return organizationDomain_; }
    void setOrganizationDomain(  fbstring domain) { organizationDomain_ = std::move(domain); }

    const   fbstring &organizationName() const { return organizationName_; }
    void setOrganizationName(  fbstring name) { organizationName_ = std::move(name); }

    const   fbstring &licenseName() const { return licenseName_; }
    void setLicenseName(  fbstring name) { licenseName_ = std::move(name); }

    const   fbstring &licenseUrl() const { return licenseUrl_; }
    void setLicenseUrl(  fbstring url) { licenseUrl_ = std::move(url); }

    const   fbstring &reportBugsTo() const { return reportBugsTo_; }
    void setReportBugsTo(  fbstring reportBugsTo) { reportBugsTo_ = reportBugsTo; }
};

/**
 * \return Branding of the Nc library.
 */
Branding branding();

} // namespace nc

/* vim:set et sts=4 sw=4: */
