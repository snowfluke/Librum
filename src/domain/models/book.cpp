#include "book.hpp"
#include <algorithm>


namespace domain::models
{

Book::Book(const QString& title, const QString& author, 
           const QString& path, const QImage& cover)
    : m_title(title), m_author(author), m_filePath(path), m_cover(cover)
{
}


const QString& Book::getTitle() const
{
    return m_title;
}

void Book::setTitle(const QString& newTitle)
{
    m_title = newTitle;
}

const QString& Book::getAuthor() const
{
    return m_author;
}

void Book::setAuthor(const QString& newAuthor)
{
    m_author = newAuthor;
}

const QString& Book::getFilePath() const
{
    return m_filePath;
}

void Book::setFilePath(const QString& newLocalPath)
{
    m_filePath = newLocalPath;
}

const QImage& Book::getCover() const
{
    return m_cover;
}

void Book::setCover(const QImage& newCover)
{
    m_cover = newCover;
}

const std::vector<Tag>& Book::getTags() const
{
    return m_tags;
}

bool Book::addTag(const Tag& tag)
{
    auto tagPosition = std::find(m_tags.begin(), m_tags.end(), tag);
    if(tagPosition != m_tags.end())
        return false;
    
    m_tags.emplace_back(tag);
    return true;
}

bool Book::removeTag(const Tag& tag)
{
    auto tagPosition = std::find(m_tags.begin(), m_tags.end(), tag);
    if(tagPosition == m_tags.end())
        return false;
    
    m_tags.erase(tagPosition);
    return true;
}

void Book::update(const Book& other)
{
    if(m_title != other.getTitle()) m_title = other.getTitle();
    if(m_filePath != other.getFilePath()) m_filePath = other.getFilePath();
    if(m_cover != other.getCover()) m_cover = other.getCover();
    if(!tagsAreTheSame(other.getTags())) m_tags = other.getTags();
}

bool Book::tagsAreTheSame(const std::vector<Tag>& other)
{
    if(m_tags.size() != other.size())
        return false;
    
    for(int i = 0; i < m_tags.size(); ++i)
    {
        if(m_tags.at(i) != other.at(i))
            return false;
    }
    
    return true;
}
    
} // namespace domain::models