#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102130
// Address: 0x102130 - 0x102294
void sub_00102130_0x102130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102130_0x102130");
#endif

    switch (ctx->pc) {
        case 0x10214cu: goto label_10214c;
        default: break;
    }

    ctx->pc = 0x102130u;

    // 0x102130: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x102130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x102134: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102138: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x102138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x10213c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10213cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102140: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x102140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x102144: 0xc040780  jal         func_101E00
    ctx->pc = 0x102144u;
    SET_GPR_U32(ctx, 31, 0x10214Cu);
    ctx->pc = 0x102148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102144u;
            // 0x102148: 0x200882d  daddu       $s1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101E00u;
    if (runtime->hasFunction(0x101E00u)) {
        auto targetFn = runtime->lookupFunction(0x101E00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10214Cu; }
        if (ctx->pc != 0x10214Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101E00_0x101e00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10214Cu; }
        if (ctx->pc != 0x10214Cu) { return; }
    }
    ctx->pc = 0x10214Cu;
label_10214c:
    // 0x10214c: 0x1440004c  bnez        $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x10214Cu;
    {
        const bool branch_taken_0x10214c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10214Cu;
            // 0x102150: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10214c) {
            ctx->pc = 0x102280u;
            goto label_102280;
        }
    }
    ctx->pc = 0x102154u;
    // 0x102154: 0xda200000  lqc2        $vf0, 0x0($s1)
    ctx->pc = 0x102154u;
    ctx->vu0_vf[0] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x102158: 0xda210010  lqc2        $vf1, 0x10($s1)
    ctx->pc = 0x102158u;
    ctx->vu0_vf[1] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x10215c: 0xda220020  lqc2        $vf2, 0x20($s1)
    ctx->pc = 0x10215cu;
    ctx->vu0_vf[2] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x102160: 0xda230030  lqc2        $vf3, 0x30($s1)
    ctx->pc = 0x102160u;
    ctx->vu0_vf[3] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x102164: 0xda240040  lqc2        $vf4, 0x40($s1)
    ctx->pc = 0x102164u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x102168: 0xda250050  lqc2        $vf5, 0x50($s1)
    ctx->pc = 0x102168u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x10216c: 0xda260060  lqc2        $vf6, 0x60($s1)
    ctx->pc = 0x10216cu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x102170: 0xda270070  lqc2        $vf7, 0x70($s1)
    ctx->pc = 0x102170u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 112)));
    // 0x102174: 0xda280080  lqc2        $vf8, 0x80($s1)
    ctx->pc = 0x102174u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 128)));
    // 0x102178: 0xda290090  lqc2        $vf9, 0x90($s1)
    ctx->pc = 0x102178u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 144)));
    // 0x10217c: 0xda2a00a0  lqc2        $vf10, 0xA0($s1)
    ctx->pc = 0x10217cu;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 160)));
    // 0x102180: 0xda2b00b0  lqc2        $vf11, 0xB0($s1)
    ctx->pc = 0x102180u;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 176)));
    // 0x102184: 0xda2c00c0  lqc2        $vf12, 0xC0($s1)
    ctx->pc = 0x102184u;
    ctx->vu0_vf[12] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 192)));
    // 0x102188: 0xda2d00d0  lqc2        $vf13, 0xD0($s1)
    ctx->pc = 0x102188u;
    ctx->vu0_vf[13] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x10218c: 0xda2e00e0  lqc2        $vf14, 0xE0($s1)
    ctx->pc = 0x10218cu;
    ctx->vu0_vf[14] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 224)));
    // 0x102190: 0xda2f00f0  lqc2        $vf15, 0xF0($s1)
    ctx->pc = 0x102190u;
    ctx->vu0_vf[15] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 240)));
    // 0x102194: 0xda300100  lqc2        $vf16, 0x100($s1)
    ctx->pc = 0x102194u;
    ctx->vu0_vf[16] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 256)));
    // 0x102198: 0xda310110  lqc2        $vf17, 0x110($s1)
    ctx->pc = 0x102198u;
    ctx->vu0_vf[17] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 272)));
    // 0x10219c: 0xda320120  lqc2        $vf18, 0x120($s1)
    ctx->pc = 0x10219cu;
    ctx->vu0_vf[18] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 288)));
    // 0x1021a0: 0xda330130  lqc2        $vf19, 0x130($s1)
    ctx->pc = 0x1021a0u;
    ctx->vu0_vf[19] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 304)));
    // 0x1021a4: 0xda340140  lqc2        $vf20, 0x140($s1)
    ctx->pc = 0x1021a4u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 320)));
    // 0x1021a8: 0xda350150  lqc2        $vf21, 0x150($s1)
    ctx->pc = 0x1021a8u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 336)));
    // 0x1021ac: 0xda360160  lqc2        $vf22, 0x160($s1)
    ctx->pc = 0x1021acu;
    ctx->vu0_vf[22] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 352)));
    // 0x1021b0: 0xda370170  lqc2        $vf23, 0x170($s1)
    ctx->pc = 0x1021b0u;
    ctx->vu0_vf[23] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 368)));
    // 0x1021b4: 0xda380180  lqc2        $vf24, 0x180($s1)
    ctx->pc = 0x1021b4u;
    ctx->vu0_vf[24] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 384)));
    // 0x1021b8: 0xda390190  lqc2        $vf25, 0x190($s1)
    ctx->pc = 0x1021b8u;
    ctx->vu0_vf[25] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 400)));
    // 0x1021bc: 0xda3a01a0  lqc2        $vf26, 0x1A0($s1)
    ctx->pc = 0x1021bcu;
    ctx->vu0_vf[26] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 416)));
    // 0x1021c0: 0xda3b01b0  lqc2        $vf27, 0x1B0($s1)
    ctx->pc = 0x1021c0u;
    ctx->vu0_vf[27] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 432)));
    // 0x1021c4: 0xda3c01c0  lqc2        $vf28, 0x1C0($s1)
    ctx->pc = 0x1021c4u;
    ctx->vu0_vf[28] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 448)));
    // 0x1021c8: 0xda3d01d0  lqc2        $vf29, 0x1D0($s1)
    ctx->pc = 0x1021c8u;
    ctx->vu0_vf[29] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x1021cc: 0xda3e01e0  lqc2        $vf30, 0x1E0($s1)
    ctx->pc = 0x1021ccu;
    ctx->vu0_vf[30] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 480)));
    // 0x1021d0: 0xda3f01f0  lqc2        $vf31, 0x1F0($s1)
    ctx->pc = 0x1021d0u;
    ctx->vu0_vf[31] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 496)));
    // 0x1021d4: 0x8e020200  lw          $v0, 0x200($s0)
    ctx->pc = 0x1021d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 512)));
    // 0x1021d8: 0x48c28000  ctc2.ni     $v0, $vi16
    ctx->pc = 0x1021d8u;
    ctx->vu0_vpu_stat4 = GPR_U32(ctx, 2);
    // 0x1021dc: 0x8e020208  lw          $v0, 0x208($s0)
    ctx->pc = 0x1021dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 520)));
    // 0x1021e0: 0x48c29000  ctc2.ni     $v0, $vi18
    ctx->pc = 0x1021e0u;
    ctx->vu0_fbrst4 = GPR_U32(ctx, 2);
    // 0x1021e4: 0x8e02020c  lw          $v0, 0x20C($s0)
    ctx->pc = 0x1021e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 524)));
    // 0x1021e8: 0x48c2a000  ctc2.ni     $v0, $vi20
    ctx->pc = 0x1021e8u;
    ctx->vu0_acc = _mm_castsi128_ps(GPR_VEC(ctx, 2));
    // 0x1021ec: 0x8e020210  lw          $v0, 0x210($s0)
    ctx->pc = 0x1021ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 528)));
    // 0x1021f0: 0x48c2a800  ctc2.ni     $v0, $vi21
    ctx->pc = 0x1021f0u;
    ctx->vu0_info = GPR_U32(ctx, 2);
    // 0x1021f4: 0x8e020214  lw          $v0, 0x214($s0)
    ctx->pc = 0x1021f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 532)));
    // 0x1021f8: 0x48c2b000  ctc2.ni     $v0, $vi22
    ctx->pc = 0x1021f8u;
    ctx->vu0_clip_flags2 = GPR_U32(ctx, 2);
    // 0x1021fc: 0x96020218  lhu         $v0, 0x218($s0)
    ctx->pc = 0x1021fcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 536)));
    // 0x102200: 0x48c20000  ctc2.ni     $v0, $vi0
    ctx->pc = 0x102200u;
    ctx->vu0_status = GPR_U32(ctx, 2) & 0xFFFF;
    // 0x102204: 0x9602021a  lhu         $v0, 0x21A($s0)
    ctx->pc = 0x102204u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 538)));
    // 0x102208: 0x48c20800  ctc2.ni     $v0, $vi1
    ctx->pc = 0x102208u;
    ctx->vu0_mac_flags = GPR_U32(ctx, 2);
    // 0x10220c: 0x9602021c  lhu         $v0, 0x21C($s0)
    ctx->pc = 0x10220cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 540)));
    // 0x102210: 0x48c21000  ctc2.ni     $v0, $vi2
    ctx->pc = 0x102210u;
    ctx->vu0_vpu_stat = GPR_U32(ctx, 2);
    // 0x102214: 0x9602021e  lhu         $v0, 0x21E($s0)
    ctx->pc = 0x102214u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 542)));
    // 0x102218: 0x48c21800  ctc2.ni     $v0, $vi3
    ctx->pc = 0x102218u;
    ctx->vu0_r = _mm_castsi128_ps(GPR_VEC(ctx, 2));
    // 0x10221c: 0x96020220  lhu         $v0, 0x220($s0)
    ctx->pc = 0x10221cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 544)));
    // 0x102220: 0x48c22000  ctc2.ni     $v0, $vi4
    ctx->pc = 0x102220u;
    { uint32_t tmp = GPR_U32(ctx, 2); std::memcpy(&ctx->vu0_i, &tmp, sizeof(tmp)); }
    // 0x102224: 0x96020222  lhu         $v0, 0x222($s0)
    ctx->pc = 0x102224u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 546)));
    // 0x102228: 0x48c22800  ctc2.ni     $v0, $vi5
    ctx->pc = 0x102228u;
    ctx->vu0_clip_flags = GPR_U32(ctx, 2);
    // 0x10222c: 0x96020224  lhu         $v0, 0x224($s0)
    ctx->pc = 0x10222cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 548)));
    // 0x102230: 0x48c23000  ctc2.ni     $v0, $vi6
    ctx->pc = 0x102230u;
    ctx->vu0_tpc = GPR_U32(ctx, 2);
    // 0x102234: 0x96020226  lhu         $v0, 0x226($s0)
    ctx->pc = 0x102234u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 550)));
    // 0x102238: 0x48c23800  ctc2.ni     $v0, $vi7
    ctx->pc = 0x102238u;
    ctx->vu0_cmsar0 = GPR_U32(ctx, 2);
    // 0x10223c: 0x96020228  lhu         $v0, 0x228($s0)
    ctx->pc = 0x10223cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 552)));
    // 0x102240: 0x48c24000  ctc2.ni     $v0, $vi8
    ctx->pc = 0x102240u;
    ctx->vu0_fbrst = GPR_U32(ctx, 2);
    // 0x102244: 0x9602022a  lhu         $v0, 0x22A($s0)
    ctx->pc = 0x102244u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 554)));
    // 0x102248: 0x48c24800  ctc2.ni     $v0, $vi9
    ctx->pc = 0x102248u;
    ctx->vu0_vpu_stat2 = GPR_U32(ctx, 2);
    // 0x10224c: 0x9602022c  lhu         $v0, 0x22C($s0)
    ctx->pc = 0x10224cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 556)));
    // 0x102250: 0x48c25000  ctc2.ni     $v0, $vi10
    ctx->pc = 0x102250u;
    ctx->vu0_tpc2 = GPR_U32(ctx, 2);
    // 0x102254: 0x9602022e  lhu         $v0, 0x22E($s0)
    ctx->pc = 0x102254u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 558)));
    // 0x102258: 0x48c25800  ctc2.ni     $v0, $vi11
    ctx->pc = 0x102258u;
    ctx->vu0_cmsar1 = GPR_U32(ctx, 2);
    // 0x10225c: 0x96020230  lhu         $v0, 0x230($s0)
    ctx->pc = 0x10225cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 560)));
    // 0x102260: 0x48c26000  ctc2.ni     $v0, $vi12
    ctx->pc = 0x102260u;
    ctx->vu0_fbrst2 = GPR_U32(ctx, 2);
    // 0x102264: 0x96020232  lhu         $v0, 0x232($s0)
    ctx->pc = 0x102264u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 562)));
    // 0x102268: 0x48c26800  ctc2.ni     $v0, $vi13
    ctx->pc = 0x102268u;
    ctx->vu0_vpu_stat3 = GPR_U32(ctx, 2);
    // 0x10226c: 0x96020234  lhu         $v0, 0x234($s0)
    ctx->pc = 0x10226cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 564)));
    // 0x102270: 0x48c27000  ctc2.ni     $v0, $vi14
    ctx->pc = 0x102270u;
    ctx->vu0_cmsar2 = GPR_U32(ctx, 2);
    // 0x102274: 0x96020236  lhu         $v0, 0x236($s0)
    ctx->pc = 0x102274u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 566)));
    // 0x102278: 0x48c27800  ctc2.ni     $v0, $vi15
    ctx->pc = 0x102278u;
    ctx->vu0_fbrst3 = GPR_U32(ctx, 2);
    // 0x10227c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10227cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_102280:
    // 0x102280: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x102280u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102284: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x102284u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102288: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10228c: 0x3e00008  jr          $ra
    ctx->pc = 0x10228Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10228Cu;
            // 0x102290: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10214Cu: goto label_10214c;
            case 0x102280u: goto label_102280;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102294u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
