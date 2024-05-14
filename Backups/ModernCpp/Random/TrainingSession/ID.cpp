#include "ID.h"


ID::ID(Country country, int year, int month, Level track, int batch_number, Location location, TrackName track_name)
    :_country(country), _year(year), _track(track), _batch_number(batch_number),
    _location(location), _track_name(track_name){}

std::string ID::CountryToString(Country country)
{
    switch (country)
    {
    case Country::India:
        return "India";
    
    case Country::Germany:
        return "Germany";
    
    case Country::Bangladesh:
        return "Bangladesh";
    
    case Country::Thiland:
        return "Thiland";

    case Country::Bangkok:
        return "Bangkok";

    case Country::Japan:
        return "Japan";

    case Country::China:
        return "China";


    default:
        return "UNKNOWN";
    }
    return std::string();
}

std::string ID::LevelToString(Level level)
{
    switch (level)
    {
    case Level::BasicTrack:
        return "BT";
    
    default:
        break;
    }
    return std::string();
}

std::string ID::TrackNameToString(TrackName trackName)
{
    switch (trackName)
    {
    case TrackName::CPP:
        return "CPP";

    case TrackName::C:
        return "C";

    case TrackName::JAVA:
        return "JAVA";
    
    case TrackName::PYTHON:
        return "PYTHON";
    
    default:
        return "UNKNOWN";
    }
    return std::string();
}

std::string ID::LocationToString(Location location)
{
    switch (location)
    {
    case Location::Pune:
        return "Pune";
    
    case Location::Banglore:
        return "Banglore";
    
    case Location::Kochi:
        return "Kochi";
    
    default:
        return "UNKNOWN";
    }
    return std::string();
}

std::ostream &operator<<(std::ostream &os, ID &rhs) {
    os << "_country: " << rhs.CountryToString(rhs.country())
       << " _year: " << rhs.year()
       << " _month: " << rhs.month()
       << " _track: " << rhs.LevelToString(rhs.track())
       << " _batch_number: " << rhs.batchNumber()
       << " _location: " << rhs.LocationToString(rhs.location())
       << " _track_name: " << rhs.TrackNameToString(rhs.trackName());
    return os;
}