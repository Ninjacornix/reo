if (ps2GsClutShadowEnabled() && gs->m_prim.tme &&
    (gs->m_prim.type == GS_PRIM_SPRITE || gs->m_prim.type == GS_PRIM_TRIANGLE ||
     gs->m_prim.type == GS_PRIM_TRISTRIP || gs->m_prim.type == GS_PRIM_TRIFAN)) {
    const auto& c = gs->activeContext();
    clut_shadow::Primitive p;
    p.tex = {c.tex0.cbp, c.tex0.psm, c.tex0.cpsm, c.tex0.csm, c.tex0.csa, c.tex0.cld};
    p.origin = {gs->m_texclut.cbw, gs->m_texclut.cou, gs->m_texclut.cov};
    p.test = c.test;
    p.zbuf = c.zbuf;
    p.clamp = c.clamp;
    p.alpha = c.alpha;
    p.fbp = c.frame.fbp;
    p.fbw = c.frame.fbw;
    p.fbmsk = c.frame.fbmsk;
    p.framePsm = c.frame.psm;
    p.ofx = c.xyoffset.ofx;
    p.ofy = c.xyoffset.ofy;
    p.context = gs->m_prim.ctxt;
    p.type = gs->m_prim.type;
    p.tcc = c.tex0.tcc;
    p.tfx = c.tex0.tfx;
    p.ta0 = gs->m_texa.ta0;
    p.ta1 = gs->m_texa.ta1;
    p.aem = gs->m_texa.aem;
    p.vertices = gs->m_prim.type == GS_PRIM_SPRITE ? 2 : 3;
    for (unsigned i = 0; i < p.vertices; ++i) {
        p.x[i] = gs->m_vtxQueue[i].x;
        p.y[i] = gs->m_vtxQueue[i].y;
    }
    ps2GsClutShadowInspect(gs, p, gs->m_vram, gs->m_vramSize);
}
