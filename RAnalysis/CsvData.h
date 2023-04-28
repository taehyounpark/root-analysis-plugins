#pragma once

#include <string>
#include <vector>
#include <utility>
#include <memory>

#include <ROOT/RCsvDS.hxx>

#include "ana/input.h"
#include "ana/reader.h"

class CsvData : public ana::input::dataset<CsvData>
{

private:
  using RCsvDS   = ROOT::RDF::RCsvDS;

public:
	class Reader;

	template <typename T>
	class Column;

public:
	CsvData(const std::string& csvFile);
	~CsvData() = default;

	ana::input::partition allocate();
	std::shared_ptr<Reader> open(const ana::input::range& part) const;

	virtual void start() override;
	virtual void finish() override;

protected:
  std::unique_ptr<RCsvDS> m_rds;

};


class CsvData::Reader : public ana::input::reader<Reader>
{

public:
	Reader(const ana::input::range& part, RCsvDS& rds);
	~Reader() = default;

	template <typename T>
	std::shared_ptr<Column<T>> read(const std::string& name) const;

	virtual void begin() override;
	virtual bool next() override;
	virtual void end() override;

protected:
  RCsvDS*      m_rds;
  long long         m_current;

};

template <typename T>
class CsvData::Column : public ana::column::reader<T>
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
std::shared_ptr<CsvData::Column<T>> CsvData::Reader::read(const std::string& name) const
{
  auto columnReaders = m_rds->GetColumnReaders<T>(name.c_str());
	return std::make_shared<Column<T>>(name,columnReaders[m_part.slot]);
}
