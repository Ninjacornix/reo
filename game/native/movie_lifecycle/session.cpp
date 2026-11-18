#include "session.hpp"
#include <limits>
#include <stdexcept>
namespace reo::native::movie_lifecycle {
struct Identity{};
namespace {struct Busy{bool& value;explicit Busy(bool& v):value(v){value=true;}~Busy(){value=false;}};}
Session::Session(std::shared_ptr<Factory> factory):factory_(std::move(factory)),identity_(std::make_shared<Identity>()){}
std::shared_ptr<Session> Session::create(std::shared_ptr<Factory> factory){if(!factory)throw std::invalid_argument("Native movie graph factory required");return std::shared_ptr<Session>(new Session(std::move(factory)));}
Session::~Session(){if(graph_){graph_->request_stop();graph_->drain();}}
bool Session::valid(const Key& key)const noexcept{return key.owner_.lock()==identity_ && key.generation_ && key.generation_==generation_;}
Key Session::key()const noexcept{Key result;result.owner_=identity_;result.generation_=generation_;return result;}
void Session::begin_stop()noexcept{closing_=true;if(graph_)graph_->request_stop();}
Open Session::construct()noexcept {
    if(generation_==std::numeric_limits<std::uint64_t>::max())return{Status::capacity,{}};
    ++generation_;retired_=false;closing_=false;failed_=false;
    auto value=factory_->construct(recipe_,generation_);graph_=std::move(value.graph);
    if(value.status!=Status::completed || !graph_){failed_=true;begin_stop();return{Status::provider_failure,{}};}
    return{Status::completed,key()};
}
Open Session::open(Recipe recipe)noexcept {
    const auto hold=weak_from_this().lock();if(!hold)return{};if(busy_)return{Status::busy,{}};if(closed_)return{Status::closed,{}};
    if(!retired_)return{Status::busy,{}};
    if(!recipe.source || !recipe.bytes || recipe.offset>recipe.source->size() || recipe.bytes>recipe.source->size()-recipe.offset)return{};
    Busy scope(busy_);recipe_=std::move(recipe);return construct();
}
Status Session::service(const Key& value)noexcept {
    const auto hold=weak_from_this().lock();if(!hold)return Status::invalid_input;if(busy_)return Status::busy;
    if(!valid(value))return Status::invalid_key;
    if(closing_ || retired_ || closed_)return Status::closed;
    Busy scope(busy_);const auto result=graph_->service();if(result!=Status::completed && result!=Status::pending){failed_=true;begin_stop();}return result;
}
Status Session::stop(const Key& value)noexcept {
    const auto hold=weak_from_this().lock();if(!hold)return Status::invalid_input;if(busy_)return Status::busy;
    if(!valid(value))return Status::invalid_key;
    if(retired_)return Status::completed;
    Busy scope(busy_);rebuilding_=false;begin_stop();return Status::pending;
}
Status Session::rebuild(const Key& value)noexcept {
    const auto hold=weak_from_this().lock();if(!hold)return Status::invalid_input;if(busy_)return Status::busy;
    if(!valid(value))return Status::invalid_key;
    if(closed_ || retired_)return Status::closed;
    if(closing_)return Status::busy;
    Busy scope(busy_);rebuilding_=true;begin_stop();return Status::pending;
}
Open Session::retire()noexcept {
    if(retired_)return{Status::completed,{}};
    if(graph_){const auto result=graph_->poll_retired();if(result!=Status::completed)return{result,{}};graph_.reset();}
    retired_=true;closing_=false;
    if(rebuilding_ && !closed_){rebuilding_=false;return construct();}
    recipe_={};return{Status::completed,{}};
}
Open Session::poll()noexcept {
    const auto hold=weak_from_this().lock();if(!hold)return{};if(busy_)return{Status::busy,{}};
    Busy scope(busy_);if(!closing_)return{closed_?Status::closed:Status::completed,retired_?Key{}:key()};return retire();
}
Status Session::close()noexcept {
    const auto hold=weak_from_this().lock();if(!hold)return Status::invalid_input;if(busy_)return Status::busy;
    Busy scope(busy_);closed_=true;rebuilding_=false;if(retired_)return Status::completed;if(!closing_)begin_stop();return retire().status;
}
Snapshot Session::snapshot()const noexcept{return{generation_,bool(graph_),closing_,retired_,rebuilding_,failed_,busy_};}
}
