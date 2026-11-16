void owned_return_points(const char* archive_path){
    const auto source=std::make_shared<const reo::assets::Source>(archive_path);Notifications notices;
    app::NativeSession host(source,profile(),notices,0);
    app::SessionScenarioResources resources(host.world(),host.archive());
    using Data=app::ScenarioDataStatus;
    check(!resources.ready()&&!resources.return_points()&&resources.load_return_points()==Data::unavailable);
    check(resources.initialize()==Data::completed&&resources.initialize()==Data::unavailable);
    host.world().scenario=28;host.world().session().asset_loading_mode=1;
    check(resources.load_return_points()==Data::completed&&!resources.return_points()); //real absent r28.rtp
    host.world().session().room_variants.restore({});
    std::shared_ptr<const s::RoomReturnPoints> held;
    for(unsigned scenario:{1u,2u,35u,41u}){
        host.world().scenario=std::uint16_t(scenario);
        check(resources.load_return_points()==Data::completed);
        const auto table=resources.return_points();check(table&&!table->rooms().empty());
        if(!held)held=table;
        const auto& row=table->rooms().front();check(!row.points.empty()&&!row.groups.empty()&&!row.groups[0].indices.empty());
        auto& variants=host.world().session().room_variants;
        check(variants.store(row.key>>8,row.key&255));
        const auto& group=row.groups[0];
        const auto position=table->point(row.key>>8,std::uint8_t(group.mode),std::uint8_t(group.kind),0,variants,host.world().session().random);
        check(position&&position->position&&position->status==(group.indices.size()==1?1:0));
        const auto closest=table->nearest(row.points[std::size_t(group.indices[0])],row.key>>8,std::uint8_t(group.mode),std::uint8_t(group.kind),variants);
        check(closest==0);
        host.world().scenario=28;check(resources.load_return_points()==Data::completed&&resources.return_points()==table);
    }
    check(held&&held->rooms().size()==14&&resources.return_points()!=held);
    check(resources.close()==Data::completed&&!resources.return_points()&&!resources.ready());
    check(held->rooms().size()==14&&resources.load_return_points()==Data::closed);
    check(host.close()==app::SessionStatus::completed);
}
