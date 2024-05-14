#ifndef ID_H
#define ID_H

#include <iostream>
#include "Employee.h"

enum class Country{
    India=1,
    Germany=2,
    Bangladesh=3,
    Thiland=4,
    Bangkok=5,
    Japan=6,
    China=7
};

enum class Level{
    BasicTrack = 1,
    AdvanceTrack = 2
};

enum class Location{
    Pune=1,
    Banglore=2,
    Kochi=3
};

enum class TrackName{
    CPP=1,
    C=2,
    JAVA=3,
    PYTHON=4
};

class ID
{
private:
    enum Country _country;
    int _year;
    int _month;
    enum Level _track;
    int _batch_number;
    enum Location _location;
    enum TrackName _track_name;

public:

    ID() = default;
    ID(const ID&) = default;
    ID(ID&&) = delete;
    ID& operator = (const ID&) = default;
    ID&& operator = (ID&&) = delete;
    ID(Country country, int year, int month, Level track, int batch_number, Location location, TrackName track_name);

    enum TrackName trackName() const { return _track_name; }
    void setTrackName(const enum TrackName &track_name) { _track_name = track_name; }

    enum Location location() const { return _location; }
    void setLocation(const enum Location &location) { _location = location; }

    int batchNumber() const { return _batch_number; }
    void setBatchNumber(int batch_number) { _batch_number = batch_number; }

    enum Level track() const { return _track; }
    void setTrack(const enum Level &track) { _track = track; }

    int month() const { return _month; }

    int year() const { return _year; }

    enum Country country() const { return _country; }
    void setCountry(const enum Country &country) { _country = country; }

    std::string CountryToString(Country country);
    std::string LevelToString(Level level);
    std::string TrackNameToString(TrackName trackName);
    std::string LocationToString(Location location);
    friend std::ostream &operator<<(std::ostream &os, const ID &rhs);
    
};

#endif // ID_H
