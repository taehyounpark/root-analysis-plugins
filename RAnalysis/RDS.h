#pragma once

#include <string>
#include <vector>
#include <utility>
#include <memory>

#include <ROOT/RVec.hxx>
#include <ROOT/RDataSource.hxx>

#include "ana/input.h"
#include "ana/reader.h"

class RDS : public ana::input::dataset<RDS>
{

private:
  using RDataSource   = ROOT::RDF::RDataSource;

public:
	class Reader;

	template <typename T>
	class Column;

public:
	RDS(std::unique_ptr<RDataSource> rds);
	~RDS() = default;

	ana::input::partition allocate();
	std::shared_ptr<Reader> open(const ana::input::range& part) const;

	virtual void start() override;
	virtual void finish() override;

protected:
  std::unique_ptr<RDataSource> m_rds;

};


class RDS::Reader : public ana::input::reader<Reader>
{

public:
	Reader(const ana::input::range& part, RDataSource& rds);
	~Reader() = default;

	template <typename T>
	std::shared_ptr<Column<T>> read(const std::string& name) const;

	virtual void begin() override;
	virtual bool next() override;
	virtual void end() override;

protected:
  ana::input::range m_part;
  RDataSource*      m_rds;
  long long         m_current;

};

template <typename T>
class RDS::Column : public ana::column::reader<T>
{

public:
	Column(const std::string& name, T** cursor) :
		ana::column::reader<T>(name),
		m_cursor(cursor)
	{}
	~Column() = default;

	virtual const T& value() const override
	{
		return static_cast<const T&>(**m_cursor);
	}

protected:
	T** m_cursor;

};

template <typename T>
std::shared_ptr<RDS::Column<T>> RDS::Reader::read(const std::string& name) const
{
  auto columnReaders = m_rds->GetColumnReaders<T>(name.c_str());
	return std::make_shared<Column<T>>(name,columnReaders[m_part.slot]);
}
