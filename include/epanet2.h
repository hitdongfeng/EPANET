/** @file epanet2.h
 @see http://github.com/openwateranalytics/epanet
 
 */

/*
 *******************************************************************
 
 EPANET2.H - Prototypes for EPANET Functions Exported to DLL Toolkit
 
 VERSION:    2.00
 DATE:       5/8/00
 10/25/00
 3/1/01
 8/15/07    (2.00.11)
 2/14/08    (2.00.12)
 AUTHORS:     L. Rossman - US EPA - NRMRL
              OpenWaterAnalytics members: see git stats for contributors
 
 *******************************************************************
 */


#ifndef EPANET2_H
#define EPANET2_H

// the toolkit can be compiled with support for double-precision as well.
// just make sure that you use the correct #define in your client code.
#ifndef EN_API_FLOAT_TYPE
  #define EN_API_FLOAT_TYPE float
#endif

// --- define WINDOWS
#undef WINDOWS
#ifdef _WIN32
  #define WINDOWS
#endif
#ifdef __WIN32__
  #define WINDOWS
#endif

// --- define DLLEXPORT
#ifndef DLLEXPORT
  #ifdef WINDOWS
    #ifdef __cplusplus
      #define DLLEXPORT extern "C" __declspec(dllexport)
    #else
      #define DLLEXPORT __declspec(dllexport) __stdcall
    #endif // __cplusplus
  #elif defined(CYGWIN)
    #define DLLEXPORT __stdcall
  #elif defined(__APPLE__)
    #ifdef __cplusplus
      #define DLLEXPORT
    #else
      #define DLLEXPORT
    #endif
  #else
    #define DLLEXPORT
  #endif
#endif

// --- Define the EPANET toolkit constants

#define EN_ELEVATION    0    /* Node parameters */
#define EN_BASEDEMAND   1
#define EN_PATTERN      2
#define EN_EMITTER      3
#define EN_INITQUAL     4
#define EN_SOURCEQUAL   5
#define EN_SOURCEPAT    6
#define EN_SOURCETYPE   7
#define EN_TANKLEVEL    8
#define EN_DEMAND       9
#define EN_HEAD         10
#define EN_PRESSURE     11
#define EN_QUALITY      12
#define EN_SOURCEMASS   13
#define EN_INITVOLUME   14
#define EN_MIXMODEL     15
#define EN_MIXZONEVOL   16

#define EN_TANKDIAM     17
#define EN_MINVOLUME    18
#define EN_VOLCURVE     19
#define EN_MINLEVEL     20
#define EN_MAXLEVEL     21
#define EN_MIXFRACTION  22
#define EN_TANK_KBULK   23
#define EN_TANKVOLUME   24
#define EN_MAXVOLUME    25

#define EN_DIAMETER     0    /* Link parameters */
#define EN_LENGTH       1
#define EN_ROUGHNESS    2
#define EN_MINORLOSS    3
#define EN_INITSTATUS   4
#define EN_INITSETTING  5
#define EN_KBULK        6
#define EN_KWALL        7
#define EN_FLOW         8
#define EN_VELOCITY     9
#define EN_HEADLOSS     10
#define EN_STATUS       11
#define EN_SETTING      12
#define EN_ENERGY       13
#define EN_LINKQUAL     14
#define EN_LINKPATTERN  15

#define EN_DURATION     0    /* Time parameters */
#define EN_HYDSTEP      1
#define EN_QUALSTEP     2
#define EN_PATTERNSTEP  3
#define EN_PATTERNSTART 4
#define EN_REPORTSTEP   5
#define EN_REPORTSTART  6
#define EN_RULESTEP     7
#define EN_STATISTIC    8
#define EN_PERIODS      9
#define EN_STARTTIME    10  /* Added TNT 10/2/2009 */
#define EN_HTIME        11
#define EN_QTIME        12
#define EN_HALTFLAG     13
#define EN_NEXTEVENT    14

#define EN_ITERATIONS     0
#define EN_RELATIVEERROR  1

#define EN_NODECOUNT    0   /* Component counts */
#define EN_TANKCOUNT    1
#define EN_LINKCOUNT    2
#define EN_PATCOUNT     3
#define EN_CURVECOUNT   4
#define EN_CONTROLCOUNT 5

#define EN_JUNCTION     0    /* Node types */
#define EN_RESERVOIR    1
#define EN_TANK         2

#define EN_CVPIPE       0    /* Link types. */
#define EN_PIPE         1    /* See LinkType in TYPES.H */
#define EN_PUMP         2
#define EN_PRV          3
#define EN_PSV          4
#define EN_PBV          5
#define EN_FCV          6
#define EN_TCV          7
#define EN_GPV          8

#define EN_NONE         0    /* Quality analysis types. */
#define EN_CHEM         1    /* See QualType in TYPES.H */
#define EN_AGE          2
#define EN_TRACE        3

#define EN_CONCEN       0    /* Source quality types.      */
#define EN_MASS         1    /* See SourceType in TYPES.H. */
#define EN_SETPOINT     2
#define EN_FLOWPACED    3

#define EN_CFS          0    /* Flow units types.   */
#define EN_GPM          1    /* See FlowUnitsType   */
#define EN_MGD          2    /* in TYPES.H.         */
#define EN_IMGD         3
#define EN_AFD          4
#define EN_LPS          5
#define EN_LPM          6
#define EN_MLD          7
#define EN_CMH          8
#define EN_CMD          9

#define EN_TRIALS       0   /* Misc. options */
#define EN_ACCURACY     1
#define EN_TOLERANCE    2
#define EN_EMITEXPON    3
#define EN_DEMANDMULT   4

#define EN_LOWLEVEL     0   /* Control types.  */
#define EN_HILEVEL      1   /* See ControlType */
#define EN_TIMER        2   /* in TYPES.H.     */
#define EN_TIMEOFDAY    3

#define EN_AVERAGE      1   /* Time statistic types.    */
#define EN_MINIMUM      2   /* See TstatType in TYPES.H */
#define EN_MAXIMUM      3
#define EN_RANGE        4

#define EN_MIX1         0   /* Tank mixing models */
#define EN_MIX2         1
#define EN_FIFO         2
#define EN_LIFO         3

#define EN_NOSAVE       0   /* Save-results-to-file flag */
#define EN_SAVE         1

#define EN_INITFLOW    10   /* Re-initialize flows flag  */


/**
 @defgroup FileManagement File Management
 */
/**
 @defgroup HydraulicFunctions Hydraulic Analysis
 
 ~~~~~~~~~~~~~~~{.c}
 int  errcode;
 long t, tstep;
 
 errcode = ENopenH();
 if (!errcode)
 {
 errcode = ENinitH(EN_SAVE);
 if (!errcode) do
 {
 tstep = 0;
 ERRCODE(ENrunH(&t));
 ERRCODE(ENnextH(&tstep));
 }
 while (tstep > 0);
 }
 
 ENcloseH();
 ~~~~~~~~~~~~~~~
 
 */


/**
 @defgroup QualityFunctions Water Quality Functions
 
 */

// --- Declare the EPANET toolkit functions
#if defined(__cplusplus)
extern "C" {
#endif
  /**
   @brief runs a complete EPANET simulation
   @param inpFile pointer to name of input file (must exist)
   @param rptFile pointer to name of report file (to be created)
   @param binOutFile pointer to name of binary output file (to be created)
   @param callback a callback function that takes a character string (char *) as its only parameter.
   @return error code
   
   The callback function should reside in and be used by the calling
   code to display the progress messages that EPANET generates
   as it carries out its computations. If this feature is not
   needed then the argument should be NULL.
   */
  int  DLLEXPORT ENepanet(char *inpFile, char *rptFile, char *binOutFile, void (*callback) (char *));
  
  /**
   @brief Opens EPANET input file & reads in network data
   @param inpFile pointer to name of input file (must exist)
   @param rptFile pointer to name of report file (to be created)
   @param binOutFile pointer to name of binary output file (to be created)
   @return error code
   @ingroup FileManagement
   */
  int  DLLEXPORT ENopen(char *inpFile, char *rptFile, char *binOutFile);
  
  /**
   @brief Saves current data to "INP" formatted text file.
   @param filename The file path to create
   @return Error code
   @ingroup FileManagement
   */
  int  DLLEXPORT ENsaveinpfile(char *filename);
  
  /**
   @brief Frees all memory and files used by EPANET
   @return Error code
   */
  int  DLLEXPORT ENclose();
  
  /**
   @brief Solves the network hydraulics for all time periods
   @return Error code
   @ingroup HydraulicFunctions
   */
  int  DLLEXPORT ENsolveH();
  
  /**
   @brief Saves hydraulic results to binary file
   @return Error code
   @ingroup HydraulicFunctions
   
   Must be called before ENreport() if no WQ simulation has been made.
   Should not be called if ENsolveQ() will be used.
   */
  int  DLLEXPORT ENsaveH();
  
  /**
   @brief Sets up data structures for hydraulic analysis
   @return Error code
   @ingroup HydraulicFunctions
   */
  int  DLLEXPORT ENopenH();
  
  /**
   @brief Initializes hydraulic analysis
   @param flag 2-digit flag where 1st (left) digit indicates if link flows should be re-initialized (1) or not (0), and 2nd digit indicates if hydraulic results should be saved to file (1) or not (0).
   @return Error code
   @ingroup HydraulicFunctions
   */
  int  DLLEXPORT ENinitH(int initFlag);
  
  /**
   @brief Run a hydraulic solution period
   @param[out] currentTime The current simulation time in seconds
   @return Error or warning code
   @ingroup HydraulicFunctions
   @see ENsolveH
   
   This function is used in a loop with ENnextH() to run
   an extended period hydraulic simulation.
   See ENsolveH() for an example.
   */
  int  DLLEXPORT ENrunH(long *currentTime);
  
  /**
   @brief Determine time (in seconds) until next hydraulic event
   @param[out] tstep Time (seconds) until next hydraulic event. 0 marks end of simulation period.
   @return Error code
   @ingroup HydraulicFunctions
   
   This function is used in a loop with ENrunH() to run an extended period hydraulic simulation.
   See ENsolveH() for an example.
   */
  int  DLLEXPORT ENnextH(long *tStep);
  
  
  /**
   @brief Frees data allocated by hydraulics solver
   @return Error code
   @ingroup HydraulicFunctions
   */
  int  DLLEXPORT ENcloseH();
  
  /**
   @brief Copies binary hydraulics file to disk
   @param filename Name of file to be created
   @return Error code
   @ingroup HydraulicFunctions
   */
  int  DLLEXPORT ENsavehydfile(char *filename);
  
  /**
   @brief Opens previously saved binary hydraulics file
   @param filename Name of file to be used
   @return Error code
   @ingroup HydraulicFunctions
   */
  int  DLLEXPORT ENusehydfile(char *filename);
  
  /**
   @brief Solves for network water quality in all time periods
   @return Error code
   @ingroup QualityFunctions
   */
  int  DLLEXPORT ENsolveQ();
  
  /**
   @brief Sets up data structures for WQ analysis
   @return Error code
   @ingroup QualityFunctions
   */
  int  DLLEXPORT ENopenQ();
  
  /**
   @brief Initializes water quality analysis
   @param saveFlag EN_SAVE (1) if results saved to file, EN_NOSAVE (0) if not
   @return Error code
   @ingroup QualityFunctions
   */
  int  DLLEXPORT ENinitQ(int saveFlag);
  
  /**
   @brief Retrieves hydraulic & WQ results at time t.
   @param[out] t Current simulation time, in seconds.
   @return Error code
   @ingroup QualityFunctions
   
   This function is used in a loop with ENnextQ() to run
   an extended period WQ simulation. See ENsolveQ() for
   an example.
   */
  int  DLLEXPORT ENrunQ(long *currentTime);
  
  /**
   @brief Advances WQ simulation to next hydraulic event.
   @param[out] tStep Time in seconds until next hydraulic event. 0 marks end of simulation period.
   @return Error code
   @ingroup QualityFunctions
   
   This function is used in a loop with ENrunQ() to run
   an extended period WQ simulation. See ENsolveQ() for
   an example.
   */
  int  DLLEXPORT ENnextQ(long *tStep);
  
  /**
   @brief Advances WQ simulation by a single WQ time step
   @param[out] timeLeft Time left in overall simulation (in seconds)
   @return Error code
   @ingroup QualityFunctions
   
   This function is used in a loop with ENrunQ() to run
   an extended period WQ simulation.
   */
  int  DLLEXPORT ENstepQ(long *timeLeft);
  
  /**
   @brief Frees data allocated by water quality solver.
   @return Error code.
   @ingroup QualityFunctions
   */
  int  DLLEXPORT ENcloseQ();
  
  /**
   @brief Writes line of text to the report file.
   @param line Text string to write
   @return Error code.
   @ingroup FileManagement
   */
  int  DLLEXPORT ENwriteline(char *line);
  
  /**
   @brief Writes simulation report to the report file
   @return Error code
   @ingroup FileManagement
   */
  int  DLLEXPORT ENreport();
  
  /**
   @brief Resets report options to default values
   @return Error code
   @ingroup FileManagement
   */
  int  DLLEXPORT ENresetreport();
  
  /**
   @brief Processes a reporting format command
   @return Error code
   @ingroup FileManagement
   */
  int  DLLEXPORT ENsetreport(char *reportFormat);
  
  /**
   @brief Retrieves parameters that define a simple control
   @param cindex Control index (position of control statement in the input file, starting from 1)
   @param[out] ctype Control type code (see EPANET2.H)
   @param[out] lindex Index of controlled link
   @param[out] setting Control setting on link
   @param[out] nindex Index of controlling node (0 for TIMER or TIMEOFDAY control)
   @param[out] level Control level (tank level, junction pressure, or time (seconds))
   @return Error code
   */
  int  DLLEXPORT ENgetcontrol(int controlIndex, int *controlType, int *linkIdx, EN_API_FLOAT_TYPE *setting, int *nodeIdx, EN_API_FLOAT_TYPE *level);
  
  /**
   @brief Retrieves the number of components of a given type in the network.
   @param code Component code (see EPANET2.H)
   @param[out] count Number of components in network
   @return Error code
   */
  int  DLLEXPORT ENgetcount(int code, int *count);
  
  /**
   @brief Gets value for an analysis option
   @param Code option code (see EPANET2.H)
   @param[out] value Option value
   @return Error code
   */
  int  DLLEXPORT ENgetoption(int code, EN_API_FLOAT_TYPE *value);
  int  DLLEXPORT ENgettimeparam(int code, long *value);
  int  DLLEXPORT ENgetflowunits(int *code);
  int  DLLEXPORT ENgetpatternindex(char *id, int *index);
  int  DLLEXPORT ENgetpatternid(int index, char *id);
  int  DLLEXPORT ENgetpatternlen(int index, int *len);
  int  DLLEXPORT ENgetpatternvalue(int index, int period, EN_API_FLOAT_TYPE *value);
  int  DLLEXPORT ENgetaveragepatternvalue(int index, EN_API_FLOAT_TYPE *value);
  int  DLLEXPORT ENgetqualtype(int *qualcode, int *tracenode);
  int  DLLEXPORT ENgeterror(int errcode, char *errmsg, int maxLen);
  int  DLLEXPORT ENgetstatistic(int code, EN_API_FLOAT_TYPE* value);
  
  int  DLLEXPORT ENgetnodeindex(char *id, int *index);
  int  DLLEXPORT ENgetnodeid(int index, char *id);
  int  DLLEXPORT ENgetnodetype(int index, int *code);
  int  DLLEXPORT ENgetnodevalue(int index, int code, EN_API_FLOAT_TYPE *value);
  int  DLLEXPORT ENgetcoord(int index, EN_API_FLOAT_TYPE *x, EN_API_FLOAT_TYPE *y);
  int  DLLEXPORT ENsetcoord(int index, EN_API_FLOAT_TYPE x, EN_API_FLOAT_TYPE y);
  
  int  DLLEXPORT ENgetnumdemands(int nodeIndex, int *numDemands);
  int  DLLEXPORT ENgetbasedemand(int nodeIndex, int demandIdx, EN_API_FLOAT_TYPE *baseDemand);
  int  DLLEXPORT ENgetdemandpattern(int nodeIndex, int demandIdx, int *pattIdx);
  
  int  DLLEXPORT ENgetlinkindex(char *id, int *index);
  int  DLLEXPORT ENgetlinkid(int index, char *id);
  int  DLLEXPORT ENgetlinktype(int index, int *code);
  int  DLLEXPORT ENgetlinknodes(int index, int *node1, int *node2);
  int  DLLEXPORT ENgetlinkvalue(int index, int code, EN_API_FLOAT_TYPE *value);
  
  int  DLLEXPORT ENgetcurve(int curveIndex, char* id, int *nValues, EN_API_FLOAT_TYPE **xValues, EN_API_FLOAT_TYPE **yValues);
  int  DLLEXPORT ENgetheadcurve(int, char *);
  
  /**
   @brief Get the type of pump
   @param linkIndex The index of the pump element
   @param outType The integer-typed pump type signifier (output parameter)
   @return Error code
   */
  int  DLLEXPORT ENgetpumptype(int linkIndex, int *outType);
  
  int  DLLEXPORT ENgetversion(int *version);
  
  int  DLLEXPORT ENsetcontrol(int cindex, int ctype, int lindex, EN_API_FLOAT_TYPE setting, int nindex, EN_API_FLOAT_TYPE level);
  int  DLLEXPORT ENsetnodevalue(int index, int code, EN_API_FLOAT_TYPE v);
  int  DLLEXPORT ENsetlinkvalue(int index, int code, EN_API_FLOAT_TYPE v);
  int  DLLEXPORT ENaddpattern(char *id);
  int  DLLEXPORT ENsetpattern(int index, EN_API_FLOAT_TYPE *f, int len);
  int  DLLEXPORT ENsetpatternvalue(int index, int period, EN_API_FLOAT_TYPE value);
  int  DLLEXPORT ENsettimeparam(int code, long value);
  int  DLLEXPORT ENsetoption(int code, EN_API_FLOAT_TYPE v);
  int  DLLEXPORT ENsetstatusreport(int code);
  int  DLLEXPORT ENsetqualtype(int qualcode, char *chemname, char *chemunits, char *tracenode);
  int  DLLEXPORT ENgetqualinfo(int *qualcode, char *chemname, char *chemunits, int *tracenode);
  int  DLLEXPORT ENsetbasedemand(int nodeIndex, int demandIdx, EN_API_FLOAT_TYPE baseDemand);
  
  int  DLLEXPORT ENgetcurveindex(char *id, int *index);
  int  DLLEXPORT ENgetcurveid(int index, char *id);
  int  DLLEXPORT ENgetcurvelen(int index, int *len);
  int  DLLEXPORT ENgetcurvevalue(int index, int pnt, EN_API_FLOAT_TYPE *x, EN_API_FLOAT_TYPE *y);
  int  DLLEXPORT ENsetcurvevalue(int index, int pnt, EN_API_FLOAT_TYPE x, EN_API_FLOAT_TYPE y);
  int  DLLEXPORT ENsetcurve(int index, EN_API_FLOAT_TYPE *x, EN_API_FLOAT_TYPE *y, int len);
  int  DLLEXPORT ENaddcurve(char *id);
  
#if defined(__cplusplus)
}
#endif

#endif //EPANET2_H
