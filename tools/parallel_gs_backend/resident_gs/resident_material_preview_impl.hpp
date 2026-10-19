// This file is compiled only by the isolated GSInterface TU. Source candidate,
// not numerical proof or runtime enrollment. No host geometry transformation.
#include "resident_material_preview.hpp"
#include "resident_preview_source_words.hpp"
#include <algorithm>
#include <cstring>
#include <type_traits>
#include <exception>
namespace ParallelGS {
GSInterface::RenderPassState::RenderPassState(const RenderPassState& rhs){*this=rhs;}
GSInterface::RenderPassState& GSInterface::RenderPassState::operator=(const RenderPassState& r){
 if(this==&r)return *this;
 positions=r.positions;attributes=r.attributes;prim=r.prim;primitive_count=r.primitive_count;
 state_vectors=r.state_vectors;held_images=r.held_images;tex_infos=r.tex_infos;tex0_infos=r.tex0_infos;
 tex_infos_has_super_samples=r.tex_infos_has_super_samples;clut_instance=r.clut_instance;latest_clut_instance=r.latest_clut_instance;
 state_vector_map.clear();for(const auto& v:r.state_vector_map)state_vector_map.emplace_replace(v.get_hash(),v.get());
 texture_map.clear();for(const auto& v:r.texture_map){auto* t=texture_map.emplace_replace(v.get_hash(),v.index,v.valid_at_texflush,v.long_term);t->valid=v.valid;}
 pending_palette_updates=r.pending_palette_updates;std::memcpy(memoized_palettes,r.memoized_palettes,sizeof(memoized_palettes));num_memoized_palettes=r.num_memoized_palettes;
 std::memcpy(instances,r.instances,sizeof(instances));num_instances=r.num_instances;current_instance=r.current_instance;
 last_triangle_is_parallelogram_candidate=r.last_triangle_is_parallelogram_candidate;is_color_feedback=r.is_color_feedback;is_depth_feedback=r.is_depth_feedback;
 is_awkward_color_feedback=r.is_awkward_color_feedback;is_potential_feedback=r.is_potential_feedback;is_potential_channel_shuffle=r.is_potential_channel_shuffle;current_primitive_is_channel_shuffle=r.current_primitive_is_channel_shuffle;
 std::memcpy(&potential_feedback,&r.potential_feedback,sizeof(potential_feedback));feedback_mode=r.feedback_mode;has_aa1=r.has_aa1;has_scanmsk=r.has_scanmsk;has_hazardous_short_term_texture_caching=r.has_hazardous_short_term_texture_caching;
 has_optimized_short_term_texture_caching=r.has_optimized_short_term_texture_caching;field_aware_rendering=r.field_aware_rendering;last_triangle_parallelogram_order=r.last_triangle_parallelogram_order;
 feedback_psm=r.feedback_psm;feedback_cpsm=r.feedback_cpsm;label_key=r.label_key;ofx=r.ofx;ofy=r.ofy;scissor_lo=r.scissor_lo;scissor_hi=r.scissor_hi;scissor_hi_x_fb=r.scissor_hi_x_fb;can_fb_wraparound=r.can_fb_wraparound;return *this;
}
void GSInterface::RenderPassState::swap(RenderPassState& r) noexcept {
 using std::swap;
 swap(positions,r.positions);
 swap(attributes,r.attributes);
 swap(prim,r.prim);
 swap(primitive_count,r.primitive_count);
 swap(tex_infos_has_super_samples,r.tex_infos_has_super_samples);
 swap(clut_instance,r.clut_instance);
 swap(latest_clut_instance,r.latest_clut_instance);
 swap(pending_palette_updates,r.pending_palette_updates);
 swap(memoized_palettes,r.memoized_palettes);
 swap(num_memoized_palettes,r.num_memoized_palettes);
 swap(instances,r.instances);
 swap(num_instances,r.num_instances);
 swap(current_instance,r.current_instance);
 swap(last_triangle_is_parallelogram_candidate,r.last_triangle_is_parallelogram_candidate);
 swap(is_color_feedback,r.is_color_feedback);
 swap(is_depth_feedback,r.is_depth_feedback);
 swap(is_awkward_color_feedback,r.is_awkward_color_feedback);
 swap(is_potential_feedback,r.is_potential_feedback);
 swap(is_potential_channel_shuffle,r.is_potential_channel_shuffle);
 swap(current_primitive_is_channel_shuffle,r.current_primitive_is_channel_shuffle);
 swap(potential_feedback,r.potential_feedback);
 swap(feedback_mode,r.feedback_mode);
 swap(has_aa1,r.has_aa1);
 swap(has_scanmsk,r.has_scanmsk);
 swap(has_hazardous_short_term_texture_caching,r.has_hazardous_short_term_texture_caching);
 swap(has_optimized_short_term_texture_caching,r.has_optimized_short_term_texture_caching);
 swap(field_aware_rendering,r.field_aware_rendering);
 swap(last_triangle_parallelogram_order,r.last_triangle_parallelogram_order);
 swap(feedback_psm,r.feedback_psm);
 swap(feedback_cpsm,r.feedback_cpsm);
 swap(label_key,r.label_key);
 swap(ofx,r.ofx);
 swap(ofy,r.ofy);
 swap(scissor_lo,r.scissor_lo);
 swap(scissor_hi,r.scissor_hi);
 swap(scissor_hi_x_fb,r.scissor_hi_x_fb);
 swap(can_fb_wraparound,r.can_fb_wraparound);
 state_vectors.swap(r.state_vectors);
 held_images.swap(r.held_images);
 tex_infos.swap(r.tex_infos);
 tex0_infos.swap(r.tex0_infos);
 state_vector_map.swap(r.state_vector_map);
 texture_map.swap(r.texture_map);
}
bool GSInterface::RenderPassState::matches(const RenderPassState& r) const {
 auto equalVector=[](const auto& a,const auto& b){return a.size()==b.size()&&(a.empty()||std::memcmp(a.data(),b.data(),a.size()*sizeof(a[0]))==0);};
 if(!equalVector(state_vectors,r.state_vectors)||!equalVector(tex_infos,r.tex_infos)||!equalVector(tex0_infos,r.tex0_infos)||held_images.size()!=r.held_images.size())return false;
 for(size_t n=0;n<held_images.size();++n)if(held_images[n].get()!=r.held_images[n].get())return false;
 size_t a=0,b=0;for(const auto& v:state_vector_map){++a;auto* w=r.state_vector_map.find(v.get_hash());if(!w||w->get()!=v.get())return false;}for(const auto& v:r.state_vector_map){(void)v;++b;}if(a!=b)return false;
 a=b=0;for(const auto& v:texture_map){++a;auto* w=r.texture_map.find(v.get_hash());if(!w||w->index!=v.index||w->valid_at_texflush!=v.valid_at_texflush||w->long_term!=v.long_term||w->valid!=v.valid)return false;}for(const auto& v:r.texture_map){(void)v;++b;}if(a!=b)return false;
 if(std::memcmp(&positions,&r.positions,sizeof(positions)))return false;
 if(std::memcmp(&attributes,&r.attributes,sizeof(attributes)))return false;
 if(std::memcmp(&prim,&r.prim,sizeof(prim)))return false;
 if(std::memcmp(&primitive_count,&r.primitive_count,sizeof(primitive_count)))return false;
 if(std::memcmp(&tex_infos_has_super_samples,&r.tex_infos_has_super_samples,sizeof(tex_infos_has_super_samples)))return false;
 if(std::memcmp(&clut_instance,&r.clut_instance,sizeof(clut_instance)))return false;
 if(std::memcmp(&latest_clut_instance,&r.latest_clut_instance,sizeof(latest_clut_instance)))return false;
 if(std::memcmp(&pending_palette_updates,&r.pending_palette_updates,sizeof(pending_palette_updates)))return false;
 if(std::memcmp(&memoized_palettes,&r.memoized_palettes,sizeof(memoized_palettes)))return false;
 if(std::memcmp(&num_memoized_palettes,&r.num_memoized_palettes,sizeof(num_memoized_palettes)))return false;
 if(std::memcmp(&instances,&r.instances,sizeof(instances)))return false;
 if(std::memcmp(&num_instances,&r.num_instances,sizeof(num_instances)))return false;
 if(std::memcmp(&current_instance,&r.current_instance,sizeof(current_instance)))return false;
 if(std::memcmp(&last_triangle_is_parallelogram_candidate,&r.last_triangle_is_parallelogram_candidate,sizeof(last_triangle_is_parallelogram_candidate)))return false;
 if(std::memcmp(&is_color_feedback,&r.is_color_feedback,sizeof(is_color_feedback)))return false;
 if(std::memcmp(&is_depth_feedback,&r.is_depth_feedback,sizeof(is_depth_feedback)))return false;
 if(std::memcmp(&is_awkward_color_feedback,&r.is_awkward_color_feedback,sizeof(is_awkward_color_feedback)))return false;
 if(std::memcmp(&is_potential_feedback,&r.is_potential_feedback,sizeof(is_potential_feedback)))return false;
 if(std::memcmp(&is_potential_channel_shuffle,&r.is_potential_channel_shuffle,sizeof(is_potential_channel_shuffle)))return false;
 if(std::memcmp(&current_primitive_is_channel_shuffle,&r.current_primitive_is_channel_shuffle,sizeof(current_primitive_is_channel_shuffle)))return false;
 if(std::memcmp(&potential_feedback,&r.potential_feedback,sizeof(potential_feedback)))return false;
 if(std::memcmp(&feedback_mode,&r.feedback_mode,sizeof(feedback_mode)))return false;
 if(std::memcmp(&has_aa1,&r.has_aa1,sizeof(has_aa1)))return false;
 if(std::memcmp(&has_scanmsk,&r.has_scanmsk,sizeof(has_scanmsk)))return false;
 if(std::memcmp(&has_hazardous_short_term_texture_caching,&r.has_hazardous_short_term_texture_caching,sizeof(has_hazardous_short_term_texture_caching)))return false;
 if(std::memcmp(&has_optimized_short_term_texture_caching,&r.has_optimized_short_term_texture_caching,sizeof(has_optimized_short_term_texture_caching)))return false;
 if(std::memcmp(&field_aware_rendering,&r.field_aware_rendering,sizeof(field_aware_rendering)))return false;
 if(std::memcmp(&last_triangle_parallelogram_order,&r.last_triangle_parallelogram_order,sizeof(last_triangle_parallelogram_order)))return false;
 if(std::memcmp(&feedback_psm,&r.feedback_psm,sizeof(feedback_psm)))return false;
 if(std::memcmp(&feedback_cpsm,&r.feedback_cpsm,sizeof(feedback_cpsm)))return false;
 if(std::memcmp(&label_key,&r.label_key,sizeof(label_key)))return false;
 if(std::memcmp(&ofx,&r.ofx,sizeof(ofx)))return false;
 if(std::memcmp(&ofy,&r.ofy,sizeof(ofy)))return false;
 if(std::memcmp(&scissor_lo,&r.scissor_lo,sizeof(scissor_lo)))return false;
 if(std::memcmp(&scissor_hi,&r.scissor_hi,sizeof(scissor_hi)))return false;
 if(std::memcmp(&scissor_hi_x_fb,&r.scissor_hi_x_fb,sizeof(scissor_hi_x_fb)))return false;
 if(std::memcmp(&can_fb_wraparound,&r.can_fb_wraparound,sizeof(can_fb_wraparound)))return false;
 return true;
}
namespace {
using GroupKind=ResidentMaterialGroupCommand::Kind;
bool rawAD6(const std::array<uint32_t,28>& w){
 if(w[0]!=32774u||((w[1]>>14)&1u)||((w[1]>>26)&3u)||(w[1]>>28)!=1u||(w[2]&15u)!=14u)return false;
 constexpr uint32_t addresses[6]{0x3b,0x14,0x06,0x08,0x34,0x36};
 for(uint32_t q=0;q<6;++q)if(w[6+4*q]!=addresses[q]||w[7+4*q]!=0u)return false;return true;
}
Vulkan::BufferHandle retain(const Vulkan::Buffer& b){auto* p=const_cast<Vulkan::Buffer*>(&b);p->add_reference();return Vulkan::BufferHandle(p);}
bool bytesEqual(const RegisterState& a,const RegisterState& b){return std::memcmp(&a,&b,sizeof(a))==0;}
void storageDependency(Vulkan::CommandBuffer& c,const Vulkan::Buffer& b,VkPipelineStageFlags2 stage,VkAccessFlags2 access){c.buffer_barrier(b,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT,stage,access);}
}
uint32_t GSInterface::resident_material_group_next_generation() const {
 return resident_group_last_generation==0xffffffffu?0u:resident_group_last_generation+1u;
}
bool GSInterface::preview_resident_material_group(const std::vector<ResidentMaterialGroupCommand>& commands,
 uint64_t epoch,uint32_t generation,ResidentMaterialGroupPreviewHandle& output){
 output.reset();if(!resident_owner_device||!epoch||!generation||generation<=resident_group_last_generation||commands.empty()||commands.size()>128||resident_group_internal||
 render_pass.primitive_count||transfer_state.host_to_local_active||render_pass.pending_palette_updates||
 sampling_rate_x_log2||sampling_rate_y_log2||!registers.prmodecont.desc.AC||renderer.resident_palette_updates_pending())return false;
 const auto palette=renderer.resident_palette_checkpoint();
 // A bounded128-command preview cannot wrap the1024-instance palette ring
 // onto its incoming selected instance. No unseen older selector is inferred.
 if(palette.next!=render_pass.clut_instance||commands.size()+1u>=CLUTInstances)return false;
 for(const auto& c:commands){if(c.kind==GroupKind::Init){if(c.mainPRIM||c.sourceVertices||c.rawAD!=std::array<uint32_t,28>{})return false;}
  else if(c.kind==GroupKind::AD6){if(c.mainPRIM||c.sourceVertices||!rawAD6(c.rawAD))return false;}
  else if(c.kind==GroupKind::Geometry){if(c.mainPRIM>2047||(c.mainPRIM&7)!=4||!c.sourceVertices||c.sourceVertices>247||c.rawAD!=std::array<uint32_t,28>{})return false;}
  else return false;
 }
 for(uint32_t job=0;job<commands.size();++job){const auto& c=commands[job];const auto& w=c.sourceParameters;
  if(w[4]!=0x5273fa3eu||w[5]||w[6]!=generation||w[7]!=job||w[2]!=495u||w[3]!=3213u||w[12]>=1024u||w[13]>=1024u||(w[14]!=0u&&w[14]!=4u)||w[15]!=65536u||
   w[32]!=uint32_t(c.kind)||w[34]!=commands.size()||w[35]||w[36]!=0x42534331u||w[37]!=1u||w[38]!=64u||w[39])return false;
  for(uint32_t r=16;r<32;++r)if(w[r])return false;for(uint32_t r=104;r<112;++r)if(w[r])return false;
  if(c.kind==GroupKind::Geometry){if(w[0]!=c.sourceVertices||w[1]!=11u*c.sourceVertices||w[8]!=(32768u|c.sourceVertices)||((w[9]>>15)&2047u)!=c.mainPRIM||w[10]!=0x412u||w[11]||
   w[40]!=1u||w[41]!=247u||w[42]||w[43])return false;for(uint32_t q=0;q<4;++q)if(w[44+q]!=w[8+q])return false;for(uint32_t q=48;q<104;++q)if(w[q])return false;}
  else{if(w[0]||w[1])return false;if(c.kind==GroupKind::AD6){if(w[40]!=2u||w[41]!=6u||w[42]||w[43])return false;for(uint32_t q=0;q<28;++q)if(w[44+q]!=c.rawAD[q])return false;for(uint32_t q=72;q<104;++q)if(w[q])return false;}
   else for(uint32_t q=40;q<104;++q)if(w[q])return false;}
 }
 auto preview=std::make_shared<ResidentMaterialGroupPreview>();preview->gs_=this;preview->ownerIdentity_=resident_group_owner_identity;preview->device_=resident_owner_device;preview->epoch_=epoch;preview->generation_=generation;preview->revision_=resident_group_revision;
 preview->initial_=registers;preview->initialPriv_=priv_registers;preview->initialCounter_=state_tracker.texflush_counter;preview->commands_=commands;preview->materials_.resize(commands.size());preview->capturedCounters_.resize(commands.size());preview->expectedParameters_.resize(commands.size());for(uint32_t j=0;j<commands.size();++j)preview->expectedParameters_[j]=commands[j].sourceParameters;
 const auto savedRegisters=registers;static_assert(std::is_trivially_copyable_v<StateTracker>);StateTracker savedTracker;std::memcpy(&savedTracker,&state_tracker,sizeof(state_tracker));
 const auto savedQueue=vertex_queue;const auto savedTail=resident_gpu_tail;auto savedPass=render_pass;const auto expectedPass=savedPass;
 std::array<GIFPath,4> savedPaths;std::copy(std::begin(paths),std::end(paths),savedPaths.begin());const auto savedDraw=draw_handler;std::array<OptimizedPacketHandler,4> savedOptimized;std::copy(std::begin(optimized_draw_handler),std::end(optimized_draw_handler),savedOptimized.begin());
 bool restored=false;resident_group_internal=true;
 const auto restore=[&]{if(restored)return;
  // Cache uploads prepare immutable images, never rasterize preview geometry.
  // Flush pending palette records before restoring the exact selector/cursor.
  std::exception_ptr cleanupFailure;
  try{flush(PAGE_TRACKER_FLUSH_CACHE_ALL,FlushReason::TextureHazard);}catch(...){cleanupFailure=std::current_exception();}
  try{if(!renderer.restore_resident_palette_checkpoint(palette))throw std::runtime_error("Palette preview restoration failed");}catch(...){if(!cleanupFailure)cleanupFailure=std::current_exception();}
  // Architectural restoration still runs when upload/cache cleanup fails.
  // A failed palette cleanup never mints a preview or a successful receipt.
  registers=savedRegisters;std::memcpy(&state_tracker,&savedTracker,sizeof(state_tracker));std::memcpy(&vertex_queue,&savedQueue,sizeof(vertex_queue));resident_gpu_tail=savedTail;render_pass.swap(savedPass);
  std::copy(savedPaths.begin(),savedPaths.end(),std::begin(paths));draw_handler=savedDraw;std::copy(savedOptimized.begin(),savedOptimized.end(),std::begin(optimized_draw_handler));resident_group_internal=false;restored=true;
  if(cleanupFailure)std::rethrow_exception(cleanupFailure);
 };
 std::vector<PageRect> writes,reads;
 try{
  for(uint32_t job=0;job<commands.size();++job){const auto& command=commands[job];
   if(command.kind==GroupKind::Init)continue;
   if(command.kind==GroupKind::AD6){gif_transfer(0,command.rawAD.data(),112);preview->finalADQReset_=true;continue;}
   // Final main PRE metadata exists for every admitted geometry job; this is
   // synchronous preview only. No absent clip PRE is synthesized on the host.
   a_d_PRIM(command.mainPRIM);vertex_queue.count=0;ResidentMaterial material;
   if(!prepare_resident_material(256,material)){restore();return false;}
   const auto& ctx=registers.ctx[registers.prim.desc.CTXT];ResidentMaterialDomain::Bounds bounds{};
   if(!ResidentMaterialDomain::bounds(ctx.scissor.desc,ctx.frame.desc.FBW,bounds)){restore();return false;}
   writes.push_back(ResidentMaterialDomain::colorPages(ctx,bounds));if(state_is_z_sensitive()&&!ctx.zbuf.desc.ZMSK)writes.push_back(ResidentMaterialDomain::depthPages(ctx,bounds));
   if(registers.prim.desc.TME){for(uint32_t level=0;level<state_tracker.tex.rect.levels;++level)reads.push_back(state_tracker.tex.page_rects[level]);
    // Supported indexed formats use the same literal CLUT rectangle as the
    // existing handle_clut_upload. Forwarded feedback palettes are excluded
    // by prepare_resident_material's no-feedback domain before this point.
    const auto& t=ctx.tex0.desc;if(is_palette_format(uint32_t(t.PSM))){uint32_t width=uint32_t(t.PSM)==PSMT8?256u:16u,height=1u;
     if(t.CSM==TEX0Bits::CSM_LAYOUT_RECT){width=uint32_t(t.PSM)==PSMT8?16u:8u;height=uint32_t(t.PSM)==PSMT8?16u:4u;}
     uint32_t x=t.CSM==TEX0Bits::CSM_LAYOUT_LINE?uint32_t(registers.texclut.desc.COU)*TEX0Bits::COU_SCALE:0u,y=t.CSM==TEX0Bits::CSM_LAYOUT_LINE?uint32_t(registers.texclut.desc.COV):0u;
     reads.push_back(compute_page_rect(uint32_t(t.CBP),x,y,width,height,uint32_t(registers.texclut.desc.CBW),uint32_t(t.CPSM)));}
   }
   auto& parameters=preview->expectedParameters_[job];parameters[16]=ctx.xyoffset.desc.OFX;parameters[17]=ctx.xyoffset.desc.OFY;parameters[18]=ctx.scissor.desc.SCAX0;parameters[19]=ctx.scissor.desc.SCAY0;parameters[20]=ctx.scissor.desc.SCAX1;parameters[21]=ctx.scissor.desc.SCAY1;std::memcpy(parameters.data()+24,&material.primitive.state,24);
   preview->capturedCounters_[job]=material.textureFlushCounter;preview->materials_[job]=std::move(material);preview->lastGeometry_=job;preview->finalADQReset_=false;
  }
  const uint32_t pages=vram_size/PGS_PAGE_ALIGNMENT_BYTES;for(const auto& write:writes)for(const auto& read:reads)if(ResidentMaterialDomain::pageOverlap(write,read,pages)){restore();return false;}
  preview->terminal_=registers;restore();
  const auto restoredPalette=renderer.resident_palette_checkpoint();
  if(!render_pass.matches(expectedPass)||!bytesEqual(registers,savedRegisters)||std::memcmp(&state_tracker,&savedTracker,sizeof(state_tracker))||std::memcmp(&vertex_queue,&savedQueue,sizeof(vertex_queue))||
   std::memcmp(paths,savedPaths.data(),sizeof(paths))||draw_handler!=savedDraw||!std::equal(savedOptimized.begin(),savedOptimized.end(),std::begin(optimized_draw_handler))||
   resident_gpu_tail.certificate.get()!=savedTail.certificate.get()||resident_gpu_tail.offset!=savedTail.offset||resident_gpu_tail.epoch!=savedTail.epoch||resident_gpu_tail.generation!=savedTail.generation||
   resident_gpu_tail.queueOwned!=savedTail.queueOwned||resident_gpu_tail.registerMask!=savedTail.registerMask||resident_gpu_tail.queueOverlayMask!=savedTail.queueOverlayMask||
   restoredPalette.next!=palette.next||restoredPalette.base!=palette.base||restoredPalette.lastRead!=palette.lastRead||std::memcmp(&priv_registers,&preview->initialPriv_,sizeof(priv_registers)))return false;
  resident_group_last_generation=generation;output=std::move(preview);return true;
 }catch(...){restore();throw;}
}
bool GSInterface::record_resident_material_group_source_certificate(const ResidentMaterialGroupPreviewHandle& p,Vulkan::CommandBuffer& cmd,
 const ResidentMaterialGroupOutputBindingHandle& binding,const Vulkan::Buffer& results){
 if(!binding||!p||binding->owner_!=resident_owner_device||binding->epoch_!=p->epoch_||binding->generation_!=p->generation_||binding->jobs_!=p->jobs())return false;
 for(const auto& b:binding->banks_)if(!b)return false;
 const auto& parameters=*binding->banks_[4];const auto& certificates=*binding->banks_[3];
 const uint64_t strides[5]{130560u,195840u,87040u,4192u,448u};
 for(unsigned bank=0;bank<5;++bank){const auto& ci=binding->banks_[bank]->get_create_info();if(ci.domain!=Vulkan::BufferDomain::Device||!(ci.usage&VK_BUFFER_USAGE_STORAGE_BUFFER_BIT)||ci.size!=strides[bank]*p->jobs())return false;}
 size_t viewIndex=0;
 for(uint32_t job=0;job<p->jobs();++job){if(p->commands_[job].kind!=GroupKind::Geometry)continue;
  const uint32_t slots=p->expectedParameters_[job][1],chunks=(slots+255u)/256u;
  for(uint32_t chunk=0;chunk<chunks;++chunk){if(viewIndex>=binding->views_.size())return false;const auto& v=binding->views_[viewIndex++];const auto& in=v.inputs;
   if(v.job!=job||v.chunk!=chunk||in.owner!=resident_owner_device||in.positions.get()!=binding->banks_[0].get()||in.attributes.get()!=binding->banks_[1].get()||in.primitives.get()!=binding->banks_[2].get()||
    in.positionOffset!=uint64_t(job)*130560u+uint64_t(chunk)*256u*48u||in.attributeOffset!=uint64_t(job)*195840u+uint64_t(chunk)*256u*72u||in.primitiveOffset!=uint64_t(job)*87040u+uint64_t(chunk)*256u*32u||
    in.primitiveCount!=std::min(256u,slots-chunk*256u)||!in.exactFixedTopologyCertificate)return false;
  }
 }
 if(viewIndex!=binding->views_.size())return false;
 if(!p||p->gs_!=this||p->ownerIdentity_!=resident_group_owner_identity||p->device_!=resident_owner_device||p->closed_||p->committed_||p->sourceCertificateRecorded_||p->revision_!=resident_group_revision||p->generation_!=resident_group_last_generation||
 !bytesEqual(registers,p->initial_)||state_tracker.texflush_counter!=p->initialCounter_||parameters.get_create_info().size!=uint64_t(p->jobs())*448u||certificates.get_create_info().size<uint64_t(p->jobs())*4192u||results.get_create_info().size<(64u+p->jobs()*64u)*4u)return false;
 for(const auto* b:{&parameters,&certificates,&results})if(b->get_create_info().domain!=Vulkan::BufferDomain::Device||!(b->get_create_info().usage&VK_BUFFER_USAGE_STORAGE_BUFFER_BIT))return false;
 Vulkan::ResourceLayout layout{};layout.sets[0].storage_buffer_mask=15u;layout.push_constant_size=16u;for(uint32_t b=0;b<4;++b)layout.sets[0].meta[b].array_size=1u;
 auto* program=resident_owner_device->request_program(ResidentPreviewSourceWords,sizeof(ResidentPreviewSourceWords),&layout);if(!program||!program->get_pipeline_layout())return false;
 Vulkan::BufferCreateInfo info{};info.domain=Vulkan::BufferDomain::Device;info.size=32u+uint64_t(p->jobs())*448u;info.usage=VK_BUFFER_USAGE_STORAGE_BUFFER_BIT|VK_BUFFER_USAGE_TRANSFER_SRC_BIT|VK_BUFFER_USAGE_TRANSFER_DST_BIT;p->privateSourceClaim_=resident_owner_device->create_buffer(info);if(!p->privateSourceClaim_)return false;
 std::vector<uint32_t> words(8u+p->jobs()*112u);for(uint32_t j=0;j<p->jobs();++j)std::copy(p->expectedParameters_[j].begin(),p->expectedParameters_[j].end(),words.begin()+8u+j*112u);
 storageDependency(cmd,*p->privateSourceClaim_,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_WRITE_BIT);cmd.update_buffer_inline(*p->privateSourceClaim_,0,words.size()*4u,words.data());
 for(const auto* b:std::array<const Vulkan::Buffer*,4>{&parameters,p->privateSourceClaim_.get(),&certificates,&results})storageDependency(cmd,*b,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_READ_BIT|VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
 cmd.set_program(program);cmd.set_storage_buffer(0,0,parameters);cmd.set_storage_buffer(0,1,*p->privateSourceClaim_);cmd.set_storage_buffer(0,2,certificates);cmd.set_storage_buffer(0,3,results);const uint32_t push[4]{p->jobs(),p->generation_,0x5273fa3eu,0u};cmd.push_constants(push,0,16);cmd.dispatch(1,1,1);
 for(const auto* b:std::array<const Vulkan::Buffer*,2>{p->privateSourceClaim_.get(),&results})storageDependency(cmd,*b,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_READ_BIT|VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
 p->outputBinding_=binding;p->nextView_=0;p->sourceCertificates_=retain(certificates);p->sourceCertificateRecorded_=true;return true;
}
bool GSInterface::submit_resident_material_group_receipt(const ResidentMaterialGroupPreviewHandle& p,
 const Vulkan::Buffer& completion,const Vulkan::Buffer& certificates){
 if(!p||p->gs_!=this||p->ownerIdentity_!=resident_group_owner_identity||p->device_!=resident_owner_device||p->closed_||p->committed_||p->receiptSubmitted_||!p->sourceCertificateRecorded_||!p->privateSourceClaim_||resident_group_internal||(p->revision_!=resident_group_revision||p->generation_!=resident_group_last_generation)||
 !bytesEqual(registers,p->initial_)||state_tracker.texflush_counter!=p->initialCounter_||std::memcmp(&priv_registers,&p->initialPriv_,sizeof(priv_registers)))return false;
 if(p->sourceCertificates_.get()!=&certificates)return false;
 const auto& c=completion.get_create_info();const auto& s=certificates.get_create_info();
 if(c.domain!=Vulkan::BufferDomain::Device||s.domain!=Vulkan::BufferDomain::Device||c.size<48||s.size<uint64_t(p->jobs())*4192||
 !(c.usage&VK_BUFFER_USAGE_TRANSFER_SRC_BIT)||!(s.usage&VK_BUFFER_USAGE_TRANSFER_SRC_BIT))return false;
 Vulkan::BufferCreateInfo info{};info.domain=Vulkan::BufferDomain::CachedHost;info.size=124;info.usage=VK_BUFFER_USAGE_TRANSFER_DST_BIT;
 p->integerHost_=resident_owner_device->create_buffer(info);if(!p->integerHost_)return false;p->sourceCompletion_=retain(completion);p->sourceCertificates_=retain(certificates);
 p->ownReceipt_=submit_resident_completion([&](Vulkan::CommandBuffer& cmd){
  storageDependency(cmd,completion,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_READ_BIT);storageDependency(cmd,certificates,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_READ_BIT);
  cmd.copy_buffer(*p->integerHost_,0,completion,0,48);cmd.copy_buffer(*p->integerHost_,48,certificates,16,16);
  cmd.copy_buffer(*p->integerHost_,64,certificates,uint64_t(p->jobs()-1)*4192+16,16);cmd.copy_buffer(*p->integerHost_,80,certificates,uint64_t(p->jobs()-1)*4192+36,12);
  storageDependency(cmd,*p->privateSourceClaim_,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_READ_BIT);cmd.copy_buffer(*p->integerHost_,92,*p->privateSourceClaim_,0,32);
  storageDependency(cmd,*p->integerHost_,VK_PIPELINE_STAGE_2_HOST_BIT,VK_ACCESS_2_HOST_READ_BIT);
 });p->receiptSubmitted_=bool(p->ownReceipt_);return p->receiptSubmitted_;
}
Vulkan::Fence GSInterface::resident_material_group_producer_fence(const ResidentMaterialGroupPreviewHandle& p) const {
 if(!p||p->gs_!=this||p->ownerIdentity_!=resident_group_owner_identity||p->device_!=resident_owner_device||!p->receiptSubmitted_||!p->ownReceipt_)return {};
 return p->ownReceipt_;
}
bool GSInterface::commit_resident_material_group(const ResidentMaterialGroupPreviewHandle& p){
 if(!p||p->gs_!=this||p->ownerIdentity_!=resident_group_owner_identity||p->device_!=resident_owner_device||p->closed_||p->committed_||!p->receiptSubmitted_||!p->ownReceipt_||resident_group_internal||
 (p->revision_!=resident_group_revision||p->generation_!=resident_group_last_generation)||!bytesEqual(registers,p->initial_)||state_tracker.texflush_counter!=p->initialCounter_||std::memcmp(&priv_registers,&p->initialPriv_,sizeof(priv_registers)))return false;
 p->ownReceipt_->wait();const auto* memory=resident_owner_device->map_host_buffer(*p->integerHost_,Vulkan::MEMORY_ACCESS_READ_BIT);if(!memory)return false;std::array<uint32_t,31> w{};std::memcpy(w.data(),memory,124);resident_owner_device->unmap_host_buffer(*p->integerHost_,Vulkan::MEMORY_ACCESS_READ_BIT);
 if(w[23]!=1u||w[24]!=0u||w[25]!=p->generation_||w[26]!=p->jobs()||w[27]!=0x53504731u||w[28]||w[29]||w[30]||w[0]||w[8]||w[9]!=0x53535431u||(w[10]!=1u&&w[10]!=2u)||w[11]!=p->jobs()||w[5]!=1u||
 w[12]!=p->generation_||w[13]!=0u||w[14]!=0x53544331u||w[15]!=1u||w[16]!=p->generation_||w[17]!=p->jobs()-1u||w[18]!=0x53544331u||w[19]!=1u||w[20]!=1u||w[21]!=1u||w[22]!=1u){p->closed_=true;return false;}
 resident_group_internal=true;
 try{for(const auto& c:p->commands_){if(c.kind==GroupKind::AD6)gif_transfer(0,c.rawAD.data(),112);else if(c.kind==GroupKind::Geometry)a_d_PRIM(c.mainPRIM);}
  p->committedRegisters_=registers;p->committedCounter_=state_tracker.texflush_counter;p->committed_=true;resident_group_internal=false;return true;
 }catch(...){resident_group_internal=false;p->closed_=true;throw;}
}
bool GSInterface::submit_resident_group_material(const ResidentMaterialGroupPreviewHandle& p,uint32_t job,const ResidentPrimitiveInputs& inputs){
 if(!p||p->gs_!=this||p->ownerIdentity_!=resident_group_owner_identity||p->device_!=resident_owner_device||p->closed_||!p->committed_||job>=p->jobs()||p->commands_[job].kind!=GroupKind::Geometry||
 (p->revision_!=resident_group_revision||p->generation_!=resident_group_last_generation)||!bytesEqual(registers,p->committedRegisters_)||state_tracker.texflush_counter!=p->committedCounter_||std::memcmp(&priv_registers,&p->initialPriv_,sizeof(priv_registers)))return false;
 if(!p->outputBinding_||p->nextView_>=p->outputBinding_->views_.size())return false;
 const auto& bound=p->outputBinding_->views_[p->nextView_];const auto& exact=bound.inputs;
 if(bound.job!=job||inputs.owner!=exact.owner||inputs.positions.get()!=exact.positions.get()||inputs.attributes.get()!=exact.attributes.get()||inputs.primitives.get()!=exact.primitives.get()||
 inputs.positionOffset!=exact.positionOffset||inputs.attributeOffset!=exact.attributeOffset||inputs.primitiveOffset!=exact.primitiveOffset||inputs.primitiveCount!=exact.primitiveCount||inputs.exactFixedTopologyCertificate!=exact.exactFixedTopologyCertificate)return false;
 const auto& snapshot=p->materials_[job];if(snapshot.textureFlushCounter!=p->capturedCounters_[job]||snapshot.registers.size()!=sizeof(RegisterState)||inputs.owner!=resident_owner_device)return false;
 // Copy before architectural projection. Any allocating copy failure leaves
 // registers, queue, counters, lease and next-view progression untouched.
 auto material=snapshot;material.pass.num_primitives=inputs.primitiveCount;
 RegisterState projected;std::memcpy(&projected,snapshot.registers.data(),sizeof(projected));const auto savedRegisters=registers;const auto savedQueue=vertex_queue;const auto savedCounter=state_tracker.texflush_counter;
 const auto restore=[&]{registers=savedRegisters;vertex_queue=savedQueue;state_tracker.texflush_counter=savedCounter;};
 // Both counters are certified: captured immutable material and sealed actual
 // committed frontend. This exact private lease permits the synchronous
 // snapshot submission; arbitrary stale material never bypasses old checks.
 resident_group_internal=true;registers=projected;vertex_queue.count=0;state_tracker.texflush_counter=snapshot.textureFlushCounter;
 try{bool accepted=submit_resident_material(material,inputs);restore();resident_group_internal=false;if(accepted)++p->nextView_;return accepted;}catch(...){restore();resident_group_internal=false;throw;}
}
bool GSInterface::adopt_resident_group_tail(const ResidentMaterialGroupPreviewHandle& p,Vulkan::BufferHandle certificate,VkDeviceSize offset){
 if(!p||p->gs_!=this||p->ownerIdentity_!=resident_group_owner_identity||p->device_!=resident_owner_device||p->closed_||!p->committed_||(p->revision_!=resident_group_revision||p->generation_!=resident_group_last_generation)||
 !bytesEqual(registers,p->committedRegisters_)||state_tracker.texflush_counter!=p->committedCounter_)return false;
 if(!p->outputBinding_||p->nextView_!=p->outputBinding_->views_.size())return false;
 if(p->lastGeometry_==~0u){p->closed_=true;return true;}
 if(certificate.get()!=p->sourceCertificates_.get()||offset!=uint64_t(p->lastGeometry_)*4192u+4032u)return false;
 if(p->finalADQReset_&&registers.internal_q!=1.0f)return false;
 resident_group_internal=true;bool accepted=adopt_resident_gpu_tail(resident_owner_device,std::move(certificate),offset,p->epoch_,p->generation_,p->commands_[p->lastGeometry_].mainPRIM,true);
 if(accepted&&p->finalADQReset_)resident_gpu_tail.registerMask&=~4u;resident_group_internal=false;p->closed_=accepted;return accepted;
}
}
